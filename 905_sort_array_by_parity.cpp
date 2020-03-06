/* Given an array A of non-negative integers, return an 
   array consisting of all the even elements of A, followed 
   by all the odd elements of A.

   You may return any answer array that satisfies this condition.
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // Just use a lambda expression which compares based on parity.
        // One key insight is that we want odd elements to come last, so they should
        // compare as greater.
        sort(A.begin(), A.end(), [](int a, int b) {return (a % 2) < (b % 2);});
        return A;
    }
};
