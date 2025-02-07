// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int ret = 0;
        //find the largest circle.
        vector<int> inDegree(n, 0);
        for(int i=0; i<n; i++) {
            inDegree[favorite[i]]++;
        };
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0)
                q.push(i);
        };
        vector<int> depth(n,1);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            int next = favorite[cur];
            depth[next] = max(depth[next], depth[cur]+1);
            inDegree[next]--;
            if(inDegree[next]==0)
                q.push(next);
        };
        int longestCycle = 0;
        int twoCycles = 0;
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0)
                continue;
            int cur = i;
            int cycleLength = 0;
            while(inDegree[cur]!=0) {
                inDegree[cur] = 0;
                cycleLength++;
                cur = favorite[cur];
            };
            if(cycleLength==2)
                twoCycles += depth[i] + depth[favorite[i]];
            else
                longestCycle = max(longestCycle, cycleLength);
        }
        return max(longestCycle, twoCycles);
    }
};