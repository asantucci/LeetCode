/* Given a string S, return the number of substrings that 
   have only one distinct letter.
*/
class Solution {
public:
    int countLetters(string S) {
        // The key idea is to make a linear traversal and collect substrings (with one character)
        // of _maximal_ length. At the end, we use a simple counting formula.
        vector<int> substrings_w_distinct_letter;
        int substring_len {};
        for (int i = 0; i < S.size(); ++i) {
            substring_len++;
            if (S[i] != S[i+1]) {
                substrings_w_distinct_letter.push_back(substring_len);
                substring_len = 0;
            }
        }
        // In each substring containing a single letter of length n, there are
        // n substrings with one character, n-1 substrings with two characters, ...
        // and 1 substring with n characters. We sum these up and realize there are
        // 1 + 2 + 3 + ... + n different substrings all with one letter contained
        // in this maximal length substring.
        int distinct_substrings {};
        for (const auto& val : substrings_w_distinct_letter)
            distinct_substrings += val*(val+1) / 2;
        return distinct_substrings;
    }
};
