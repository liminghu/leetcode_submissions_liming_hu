// https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
        vector<vector<pair<int, int>>> reverse_al(n); //reverse adj list

        for(auto& edge: edges) {
            reverse_al[edge[1]].push_back({edge[0], edge[2]});
        }
        int l =1, r = 1000001;
        while(l<r) {
            int mid = (l+r)/2;
            vector<int> visited(n);
            if( dfs(0, mid, reverse_al, visited) == n) 
                r = mid;
            else
                l = mid+1;
        }
        return l == 1000001? -1: l;
    }
    int dfs(int i, int mid, vector<vector<pair<int, int>>>& reverse_al, vector<int>& visited) {
        int res = 1;
        visited[i] = 1;
        
        for(auto [j, w]: reverse_al[i]) {
            if( w<=mid && !visited[j])
                res += dfs(j, mid, reverse_al, visited);
        }
        return res;
    }
};