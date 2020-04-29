class Solution {
public:
    // Slow O(n^2) solution
    vector<int> twoSum(vector<int>& nums, int target) {
        for (unsigned i = 0; i < nums.length() - 1; ++i)
            for (unsigned j = i + 1; j < nums.length(); ++j)
                if (nums[i] + nums[j] == target)
                    return {i, j}
    }
    // Fast O(n) solution using contains (requires C++20).
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            // Before C++20, we have to use a find method.
            // Note that worst case is linear time complexity...
            // whence method reduces to O(n^2).
            auto search = m.find(target - nums[i]);
            if (search != m.end())
                return {search->second, i};
            m[nums[i]] = i;
            // However, in C++20 there is an O(1) contains.
            // if (m.contains(target - nums[i]))
            //     return {m[target - nums[i]], i};
        }
        return {-1, -1};
    }
};
