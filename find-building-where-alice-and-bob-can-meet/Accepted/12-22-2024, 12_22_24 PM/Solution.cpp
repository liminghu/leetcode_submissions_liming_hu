// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        //queries[i] = [ai, bi]. 
        for(int i=0; i<queries.size(); i++) {
            if(queries[i][0] > queries[i][1])
                swap(queries[i][0], queries[i][1]);
            queries[i].push_back(i);
        };
        sort(queries.begin(), queries.end(), [](vector<int>&q1, vector<int>& q2) {return q1[1] > q2[1]; }); 
        vector<int> rets(queries.size(), -1);
        int i=n-1;
        map<int, int> mp; //height-> idx
        for(auto& q: queries) {
            int a = q[0], b = q[1], idx = q[2];
            while(i>=b) {
                while(!mp.empty() && heights[i] >= (mp.begin()->first))
                    mp.erase(mp.begin());
                mp[heights[i]] = i;
                i--;
            };
            if(heights[a]<heights[b] || a == b) {
                rets[idx] = b;
                continue;
            }
            int mh = max(heights[a], heights[b]);
            auto iter = mp.upper_bound(mh);
            if(iter != mp.end())
                rets[idx] = iter->second;
            else
                rets[idx] = -1;
        }
        return rets;
    }
};