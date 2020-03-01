/* Given an array nums of integers, return how many of 
   them contain an even number of digits.
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n_evens {};
        for (int val : nums) {
            // Simply coerce the integer to a string and
            // check its length modulo 2.
            string s = to_string(val);
            if (s.size() % 2 == 0) n_evens++;
        }
        return n_evens;
    }
};
