/* Balanced strings are those who have equal quantity of 
   'L' and 'R' characters.

   Given a balanced string s split it in the maximum 
   amount of balanced strings.

   Return the maximum amount of splitted balanced strings.
*/
class Solution {
public:
    int balancedStringSplit(string s) {
        // The trick is to maintain a 'balance' variable which we will
        // increment by unit value when we run into an 'L' and we will
        // decrement by unit value when we run into an 'R'. Each time
        // the balance var "hits" zero, we know that we can split off 
        // a piece of the string into a balancedSubString. Note that the
        // remainder is balanced by virtue of the original input being balanced.
        int balance {};
        int num_splits {};
        for (char c : s) {
            c == 'L' ? ++balance : --balance;
            if (balance == 0) num_splits++;
        }
        return num_splits;
    }
};
