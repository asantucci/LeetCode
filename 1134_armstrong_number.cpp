/*
  The k-digit number N is an Armstrong number if and only if 
  the k-th power of each digit sums to N.

  Given a positive integer N, return true if and only if it 
  is an Armstrong number.
*/
class Solution {
public:
    bool isArmstrong(int N) {
        int sum{};
        string s = to_string(N);
        for (char c : s)
            sum += pow(c - '0', s.size());
        return sum == N;
    }
};
