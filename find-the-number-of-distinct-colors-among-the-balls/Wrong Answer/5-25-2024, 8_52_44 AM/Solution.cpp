// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);

        unordered_map<int, vector<int>> current_res;  //color, ball1, ball3, ....
        for(int i=0; i<queries.size(); i++) {
            vector<int> current_paint = queries[i];

            if(current_res.find(current_paint[1])== current_res.end()) { //current color not found
                current_res[current_paint[1]].push_back(current_paint[0]);
                ans[i] = current_res.size();
            } else { ////current color found
                vector<int>& balls = current_res[current_paint[1]];
                for(auto j=balls.begin(); j!=balls.end(); j++) {
                    if(*j == current_paint[0]) {
                        balls.erase(j);
                        break;
                    }

                }
                if(balls.size() == 0) 
                    current_res.erase(current_paint[1]);

                current_res[current_paint[1]].push_back(current_paint[0]);
                ans[i] = current_res.size();
            }

        };

        return ans;

        
    }
};