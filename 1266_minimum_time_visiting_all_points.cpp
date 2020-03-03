/* On a plane there are n points with integer coordinates 
   points[i] = [xi, yi]. Your task is to find the minimum 
   time in seconds to visit all points.

   You can move according to the next rules:

   In one second always you can either move vertically, 
   horizontally by one unit or diagonally (it means to move 
   one unit vertically and one unit horizontally in one second).
   You have to visit the points in the same order as they appear 
   in the array.
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> posn = points[0];
        int time_taken {};
        for (int i = 1; i < points.size(); ++i) {
            while(abs(points[i][0] - posn[0]) and abs(points[i][1] - posn[1])) {
                posn[0] += points[i][0] > posn[0] ? 1 : -1;
                posn[1] += points[i][1] > posn[1] ? 1 : -1;
                time_taken++;
            }
            while(abs(points[i][0] - posn[0])) {
                posn[0] += points[i][0] > posn[0] ? 1 : -1;
                time_taken++;
            }
            while(abs(points[i][1] - posn[1])) {
                posn[1] += points[i][1] > posn[1] ? 1 : -1;
                time_taken++;
            }
        }
        return time_taken;
    }
};
