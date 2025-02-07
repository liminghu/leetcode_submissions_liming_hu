// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);

        unordered_map<int, vector<int>> current_res;
        for(int i=0; i<queries.size(); i++) {
            vector<int> current_paint = queries[i];
            current_res[current_paint[0]].push_back(current_paint[1]);
            ans[i] = current_res.size();
        };

        return ans;

        
    }
};