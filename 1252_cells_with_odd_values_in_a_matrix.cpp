/* Given n and m which are the dimensions of a matrix 
   initialized by zeros and given an array indices where 
   indices[i] = [ri, ci]. For each pair of [ri, ci] you 
   have to increment all cells in row ri and column ci by 1.

   Return the number of cells with odd values in the matrix 
   after applying the increment to all indices.
*/
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        // Loop through our indices and apply the corresponding increment.
        int mat[n][m] {};
        for (const auto& vec : indices) {
            for (int j = 0; j < m; ++j)
                mat[vec[0]][j] += 1;
            for (int i = 0; i < n; ++i)
                mat[i][vec[1]] += 1;
        }
        // After incrementing our matrix appropriately, we can simply iterate
        // over elements and check parity, keeping track of a counter along the way.
        int counter{};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                counter += (mat[i][j] & 1);
        return counter;
    }
};
