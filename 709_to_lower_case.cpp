/* Implement function ToLowerCase() that has a string parameter 
   str, and returns the same string in lowercase.
*/
class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for (char c : str)
            // We need to lowercase our letter. Remember that a string::append
            // method can accept the (i) num chars to insert and (ii) the character to be inserted.
            res.append(1, tolower(c));
        return res;
    }
};
