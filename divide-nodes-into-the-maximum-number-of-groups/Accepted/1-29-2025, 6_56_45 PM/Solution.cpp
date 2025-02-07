// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups

class Solution {
    vector<int> next[501];
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(auto edge: edges) {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        };
        unordered_map<int, int> mp;
        for(int start=1; start<=n; start++) {
            int d = 0;
            int smallestId = INT_MAX;
            vector<int> level(501);
            queue<int> q;
            q.push(start);
            level[start] = 1; //use it as visited.
            while(!q.empty()) {
                d++;
                int sz = q.size();
                for(int j=0; j<sz; j++) {
                    int cur = q.front();
                    q.pop();
                    smallestId = min(smallestId, cur);
                    for(int nxt: next[cur]) {
                        if(level[nxt]==0) {
                            level[nxt] = d+1;
                            q.push(nxt);
                        } else if(level[nxt]==d)
                            return -1;
                    }
                }
            }
            mp[smallestId] = max(mp[smallestId], d);
        }
        int ret = 0;
        for(auto [k,v]: mp) 
            ret += v; //add all the grps.
        return ret;
    }
};