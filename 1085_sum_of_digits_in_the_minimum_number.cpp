/* Given an array A of positive integers, let S be the sum 
   of the digits of the minimal element of A.

   Return 0 if S is odd, otherwise return 1.
*/
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_val = A[0];
        for (const auto& val : A)
            min_val = val < min_val ? val : min_val;
        string s = to_string(min_val);
        int sum{};
        for (char c : s)
            sum += c - '0';
        return !(sum & 1);
    }
};
