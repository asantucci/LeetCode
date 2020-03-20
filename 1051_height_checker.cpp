/* Students are asked to stand in non-decreasing order of 
   heights for an annual photo.

   Return the minimum number of students that must move in 
   order for all students to be standing in non-decreasing 
   order of height.

   Notice that when a group of students is selected they 
   can reorder in any possible way between themselves and the 
   non selected students remain on their seats.
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Simply create a new sorted array, sort, and count the number of 
        // elements that are not equal across arrays.
        int moves {};
        vector<int> sorted(heights);
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < heights.size(); ++i)
            if (sorted[i] != heights[i])
                moves++;
        return moves;
    }
};
