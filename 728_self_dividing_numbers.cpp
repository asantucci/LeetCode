/* A self-dividing number is a number that is divisible by 
   every digit it contains.

   For example, 128 is a self-dividing number because 
   128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

   Also, a self-dividing number is not allowed to contain 
   the digit zero.

   Given a lower and upper number bound, output a list of 
   every possible self dividing number, including the bounds 
   if possible.
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> solns;
        for (; left <= right; left++) {
            string s = to_string(left);
            bool is_soln = true;
            for (char c : s) {
                // Check to see if the character is zero, if so it's not a self-dividing number.
                if (c - '0' == 0) {is_soln = false; break;}
                // Now, check to see if the digit passes the self-dividing test.
                if (left % (c - '0') != 0) {is_soln = false; break;}
            }
            if (is_soln) solns.push_back(left);
        }
        return solns;
    }
};
