/* Given an integer n, return any array containing n unique 
   integers such that they add up to 0.
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        // We'll make our vector to be the numbers [0, 1, 2, ..., n-2, -(n-2)*(n-1)/2]
        // where the last term comes from applying Euler's counting formula to the first
        // n-1 terms (where the first is zero...so there are n-2 non-zero strictly increasing
        // integers)
        for (int i = 0; i < n - 1; ++i)
            result.push_back(i);
        result.push_back(-(n-2)*(n-1) / 2);
        return result;
    }
};
