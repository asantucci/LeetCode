/* A valid parentheses string is either empty (""), 
   "(" + A + ")", or A + B, where A and B are valid 
   parentheses strings, and + represents string concatenation.  
   For example, "", "()", "(())()", and "(()(()))" are all 
   valid parentheses strings.

   A valid parentheses string S is primitive if it is nonempty, 
   and there does not exist a way to split it into S = A+B, 
   with A and B nonempty valid parentheses strings.

   Given a valid parentheses string S, consider its primitive 
   decomposition: S = P_1 + P_2 + ... + P_k, where P_i are 
   primitive valid parentheses strings.

   Return S after removing the outermost parentheses of 
   every primitive string in the primitive decomposition of S.
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        // We do a linear traversal and maintain a balance counter for
        // the parentheses, realizing that in the primitive decomposition
        // the number of '(' and ')' must match.
        // Each time the balance goes to zero, we've found a primitive substring
        // and we can append everything but the outer parentheses to the result.
        int beg{}, idx{}, balance{};
        string result;
        while (idx < S.size()) {
            if (S[idx] == '(') balance++;
            else if (S[idx] == ')') balance--;
            if (!balance) {
                for (int i = beg+1; i < idx; ++i)
                    result.append(1, S[i]);
                beg = idx+1;
            }
            idx++;
        }
        return result;
    }
};
