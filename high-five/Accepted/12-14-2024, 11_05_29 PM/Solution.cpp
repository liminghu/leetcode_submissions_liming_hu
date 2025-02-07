// https://leetcode.com/problems/high-five

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        //items[i] = [IDi, scorei] represents one score from a student with IDi
        //result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.
        map<int, priority_queue<int>> mp;
        for(int i=0; i<items.size(); i++) {
            int id = items[i][0];
            int score = items[i][1];
            mp[id].push(score);
        };
        vector<vector<int>> rets;
        for(auto item: mp) {
            int id = item.first;
            int score = 0;
            int i=0;
            priority_queue<int> scores = item.second;
            while(i<5) {
                int score_i = scores.top();
                scores.pop();
                i++;
                score += score_i;
            }
            rets.push_back({id, score/5});
        }

        return rets;
    }
};