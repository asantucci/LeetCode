/* The Hamming distance between two integers is the number of 
   positions at which the corresponding bits are different.

   Given two integers x and y, calculate the Hamming distance.
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int sum = 0;
        while (n) {
            sum += n & 1;
            n = n >> 1;
        }
        return sum;
    }
};
