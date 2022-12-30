string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        // We're considering substrings, so we need to keep track of starting and ending indices.
        // Realize that if we were to, say, loop over all {i, j} pairs and calculate IsPalindrome
        // we'd end up with a O(N^3) solution since IsPalindrome is O(N) via two-pointers. But,
        // realize that there is a lot of duplicated computation that is happening in the above
        // "implementation" method; realize that if P(i-1, j+1) = P(i,j) && s[i-1] == s[j+1];
        // This is basically to say that if a substr indexed from {i,j} is a Palindrome, then
        // the substring {i-1, j+1} is also a Palindrome If and Only If s[i-1] == s[j+1].
        // With this let's think of a DP based solution. There are a few base cases to account for.
        // Trivially, all length-one substrings are palindromes.
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        }
        // Be careful here, recognize that our DP is formulated as a Bottom-Up since we require
        // P(i, j) = P(i+1,j-1) && s[i] == s[j].
        // If we started loop (i = s.size() - 1; i >= 0; --i) and then loop (j = i; j < s.size(); ++j)
        // that the very first time we check our condition P(i,j) && s[i-1] == s[j+1] we'll be examining
        // a length-3-substring. This misses out on all length-two substrings where the characters are
        // equal. So, we need to fill in this base case as well.
        for (int i = 0; i + 1< s.size(); ++i)
          if (s[i] == s[i+1])
            dp[i][i+1] = true;
        // Also, recognize that we don't need to fill in the entire 2D matrix we created, just
        // the upper triangular portion, since the entry [i][j] indicates a substr starting at
        // index i and going up through (inclusive of) index j, and so entries where i > j
        // don't make sense.
        // Note that s.size() - 1 is safe since s.size() >= 1 by virtue of early return above.
        int max_len = 0;
        int substr_start = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] &&
                    // Either it's a length-2 string where the chars are equal.
                    (j - i <= 1 || 
                    // Or the substring is a palindrome.
                    (dp[i+1][j-1] && i + 1 < s.size() && j - 1 >= 0))) {
                    dp[i][j] = true;
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        substr_start = i;
                    }
                }
            }
        }
        return s.substr(substr_start, max_len);
}
