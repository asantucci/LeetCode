/* Given an array of integers arr, write a function 
   that returns true if and only if the number of occurrences 
   of each value in the array is unique.
 */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // The idea is to count the number of times each value appears in our input
        // We'll then pipe the counts to a vector, sort it, and check that adjacent
        // elements are non-equal. (If adjacent elements are equal it means that two
        // values have the same count, so we return false in that case.)
        map<int,int> counts;
        for (const auto& val : arr)
            counts[val]++;
        vector<int> occurrences;
        for (const auto& kv : counts)
            occurrences.push_back(kv.second);
        sort(occurrences.begin(), occurrences.end());
        for (int i = 0; i < occurrences.size() - 1; ++i)
            if (occurrences[i] == occurrences[i+1]) return false;
        return true;
    }
};
