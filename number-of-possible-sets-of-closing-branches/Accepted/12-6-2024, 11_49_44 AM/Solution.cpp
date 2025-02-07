// https://leetcode.com/problems/number-of-possible-sets-of-closing-branches

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        //where roads[i] = [ui, vi, wi] represents the undirected road between branches ui and vi with length wi.
        int ret = 0;
        for(int state=0; state<(1<<n); state++) {
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX/3));
            for(int i=0; i<n; i++) {
                if( ((state>>i)&1)==0 ) continue;
                dist[i][i] = 0;
            }
            for(auto road:roads) {   //Floyd algorithm.
                int start = road[0]; 
                int end = road[1];
                int w = road[2];
                if( ((state>>start)&1)==0 ) continue;
                if( ((state>>end)&1)==0 ) continue;
                for(int i=0; i<n; i++) {
                   if( ((state>>i)&1)==0 ) continue;
                   for(int j=0; j<n; j++) {
                        if( ((state>>j)&1)==0 ) continue;
                        dist[i][j] = min(dist[i][j], dist[i][start]+w+dist[end][j]); 
                        dist[i][j] = min(dist[i][j], dist[i][end]+w+dist[start][j]); 
                   } 
                }
            }
            int flag = 1;
            for(int i=0; i<n; i++) {
                if( ((state>>i)&1)==0 ) continue;
                for(int j=0; j<n; j++) {
                    if( ((state>>j)&1)==0 ) continue;
                    if(dist[i][j] > maxDistance) {
                        flag = 0;
                        break;
                    }
                }
                if(flag==0)
                    break; 
            }
            if(flag==1)
                ret++;
        }
        return ret;
    }
};