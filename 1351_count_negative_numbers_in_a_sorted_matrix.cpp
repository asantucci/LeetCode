/* Given a m * n matrix grid which is sorted in non-increasing 
   order both row-wise and column-wise. 

   Return the number of negative numbers in grid.
*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negatives {};
        for (const auto& vec : grid)
            for (const auto& val : vec)
                negatives += val < 0 ? 1 : 0;
        return negatives;
    }
};
