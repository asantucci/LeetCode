/* There is a special keyboard with all keys in a single row.

   Given a string keyboard of length 26 indicating the layout 
   of the keyboard (indexed from 0 to 25), initially your 
   finger is at index 0. To type a character, you have to 
   move your finger to the index of the desired character. 
   The time taken to move your finger from index i to index 
   j is |i - j|.

   You want to type a string word. Write a function to 
   calculate how much time it takes to type it with one finger.
*/
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int time_taken {};
        int init_posn {};
        // For each character in the word we're trying to type...
        for (const char c : word) {
            // Find out where the key lay on the keyboard, and
            // determine the time-taken
            // based on the difference in absolute value from
            // where our index finger was last pointed.
            int idx = keyboard.find(c);
            time_taken += abs(idx - init_posn);
            // Update the position of our index finger.
            init_posn = idx;
        }
        return time_taken;
    }
};
