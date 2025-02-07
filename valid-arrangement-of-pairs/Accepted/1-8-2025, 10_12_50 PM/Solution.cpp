// https://leetcode.com/problems/valid-arrangement-of-pairs

class Solution {
    unordered_map<int, int> inDegree;
    unordered_map<int, int> outDegree;
    unordered_map<int, vector<int>> adj;
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //pairs[i] = [starti, endi].
        for(auto& pair: pairs) {
            int a = pair[0], b = pair[1];
            inDegree[b]++;
            outDegree[a]++;
            adj[a].push_back(b);
        }
        int start = -1;
        for(auto x: adj) {
            int p = x.first;
            if(outDegree[p]-inDegree[p] == 1)
                start = p;
        }
        if(start==-1)
            start = pairs[0][0];
        vector<int> path; // p0, p1, p2...
        dfs(start, path);
        reverse(path.begin(), path.end());
        vector<vector<int>> rets;
        for(int i=0; i<path.size()-1; i++) {
            rets.push_back({path[i], path[i+1]});
        }
        return rets;
    }
    void dfs(int start, vector<int>& path) {
        while(adj[start].size()>0) {
            int next = adj[start].back();
            adj[start].pop_back();
            dfs(next, path);
        }
        path.push_back(start);
    }
};