/* Given an array arr, replace every element in that array 
   with the greatest element among the elements to its right, 
   and replace the last element with -1.

   After doing so, return the array.
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // The general idea is to iterate over the input collection in reverse.
        // We keep a running maximum and replace elements with this.
        // One key detail is that "greatest element among the elements to its right"
        // which implies that we first must update an element before updating the running
        // maximum.
        vector<int> result(arr.size());
        result[arr.size() - 1] = -1;
        int max = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i) {
            // I.e. it is here that we want to update the element...
            result[i] = max;
            // ... then consider if the max should be updated.
            // On the next iteration, the max will have considered all elements to the right.
            if (arr[i] > max) max = arr[i];
        }
        return result;
    }
};
