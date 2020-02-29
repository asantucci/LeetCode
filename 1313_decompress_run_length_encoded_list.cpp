/* We are given a list nums of integers representing 
   a list compressed with run-length encoding.

   Consider each adjacent pair of elements [a, b] = [nums[2*i], 
   nums[2*i+1]] (with i >= 0).  For each such pair, 
   there are a elements with value b in the decompressed list.

   Return the decompressed list.
*/
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressed;
        // Iterate over our collection with a stride-length
        // of two.
        for (int i = 0; i < nums.size(); i += 2)
            // When we encounter element 'a', it instructs
            // us how many push_backs to perform.
            for (int j = 0; j < nums[i]; ++j)
                // Remember though, we're pushing back 'b'
                // (at idx i+1), not 'a' (at idx i).
                decompressed.push_back(nums[i+1]);
        return decompressed;
    }
};
