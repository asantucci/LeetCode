/* Given a list of scores of different students, return the 
   average score of each student's top five scores in the 
   order of each student's id.

   Each entry items[i] has items[i][0] the student's id, 
   and items[i][1] the student's score.  The average score 
   is calculated using integer division.
*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // First we need to accumulate a listing of scores for each student-id.
        map<int, vector<int>> id_to_scores;
        for (const auto& id_score : items)
            id_to_scores[id_score[0]].push_back(id_score[1]);
        vector<vector<int>> result;
        // For each student's scores...
        for (auto& kv : id_to_scores) {
            // First we sort their scores in descending order (high to low)
            sort(kv.second.begin(), kv.second.end(), [](int a, int b) {return a > b;});
            // We then take an (integer) average over the first five elements.
            int avg = 0;
            for (int i = 0; i < 5; ++i)
                avg += kv.second[i];
            avg /= 5;
            // Critically, we used an ordered map so the results will be in student-id
            // order.
            result.push_back({kv.first, avg});
        }
        return result;
    }
};
