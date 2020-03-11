/* Given an array of integers A sorted in non-decreasing order, 
   return an array of the squares of each number, also in 
   sorted non-decreasing order.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        for (const auto& val : A)
            result.push_back(val*val);
        sort(result.begin(), result.end());
        return result;
    }
};
