/* Given a non-negative integer num, return the number 
   of steps to reduce it to zero. If the current number 
   is even, you have to divide it by 2, otherwise, you 
   have to subtract 1 from it.
 */
class Solution {
public:
    int numberOfSteps (int num) {
        // Go ahead and zero initialize our step counter.
        int steps {};
        // While the number is non-zero, apply the relevant step.
        while (num) {
            if (num & 1) num--;
            else num /= 2;
            // Each iteration is exactly one step.
            steps++;
        }
        return steps;
    }
};
