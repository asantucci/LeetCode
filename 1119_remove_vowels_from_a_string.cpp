/* Given a string S, remove the vowels 'a', 'e', 'i', 'o', 'u'
   from it, and return the string.
 */
class Solution {
public:
    string removeVowels(string S) {
        // Shove all vowels into a string, it's easy enough to iterate over one character at a time.
        string vowels = "aeiou";
        for (char c : vowels) {
            int idx = S.find(c);
            // While there are still vowels in our string, remove them one at a time!
            while (idx != string::npos) {
                S.erase(idx, 1);
                idx = S.find(c);
            }
        }
        return S;
    }
};
