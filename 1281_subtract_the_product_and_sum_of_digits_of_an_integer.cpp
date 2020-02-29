/* Given an integer number n, return the difference 
   between the product of its digits and the sum of its digits.
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        string s {to_string(n)};
        int sum = 0, prod = 1;
        for (char c : s) {
            sum  += c - '0';
            prod *= c - '0';
        }
        return prod - sum;
    }
};
