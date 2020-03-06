/* In a array A of size 2N, there are N+1 unique elements, 
   and exactly one of these elements is repeated N times.

   Return the element repeated N times.
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> counts;
        for (const auto& val : A)
            counts[val]++;
        int result; // Little bit sketchy, as the value is uninitialized.
        // But, we are guaranteed that one of the input elements meets the following
        // predicate, so result will eventually get filled in.
        for (const auto& kv : counts)
            if (kv.second == A.size()/2) result = kv.first;
        return result;
    }
};
