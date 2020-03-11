/* There is a robot starting at position (0, 0), the origin, 
   on a 2D plane. Given a sequence of its moves, judge if this 
   robot ends up at (0, 0) after it completes its moves.

   The move sequence is represented by a string, and the 
   character moves[i] represents its ith move. Valid moves 
   are R (right), L (left), U (up), and D (down). If the robot 
   returns to the origin after it finishes all of its moves, 
   return true. Otherwise, return false.

   Note: The way that the robot is "facing" is irrelevant. "R" 
   will always make the robot move to the right once, "L" 
   will always make it move left, etc. Also, assume that the 
   magnitude of the robot's movement is the same for each move.
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        // Simply maintain both a Left-Right counter and a Up-Down counter.
        // Then, a return to origin means both up-down and left-right counters
        // have worked their way back to zero.
        int lr{}, ud{};
        for (char c : moves) {
            switch(c) {
                case 'R' : lr++; break;
                case 'L' : lr--; break;
                case 'U' : ud++; break;
                case 'D' : ud--; break;
            }
        }
        return !lr and !ud;
    }
};
