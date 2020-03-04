/*
  Given three integer arrays arr1, arr2 and arr3 sorted 
  in strictly increasing order, return a sorted array of 
  only the integers that appeared in all three arrays.
*/
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        // Create a map which counts how many times we see a particular value ACROSS all three
        // input arrays. In the end, the values which are associated with a count of three 
        // correspond to being in all three input arrays.
        map<int, int> counts;
        for (const auto& val : arr1)
            counts[val] += 1;
        for (const auto& val : arr2)
            counts[val] += 1;
        for (const auto& val : arr3)
            counts[val] += 1;
        vector<int> result;
        for (const auto& kv : counts)
            if (kv.second == 3) result.push_back(kv.first);
        // sort(result.begin(), result.end()); Note we're using an ordered map.
        return result;
    }
};
