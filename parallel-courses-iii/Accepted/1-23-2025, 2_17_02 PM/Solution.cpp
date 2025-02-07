// https://leetcode.com/problems/parallel-courses-iii

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //n, which indicates that there are n courses labeled from 1 to n
        //relations[j] = [prevCoursej, nextCoursej]
        //time[i] denotes how many months it takes to complete the (i+1)th course.
        
        vector<int> inDegree(n, 0);
        vector<vector<int>> next(n);
        for(vector<int> relation: relations) {
            int prevCoursej = relation[0]-1;
            int nextCoursej = relation[1]-1;
            next[prevCoursej].push_back(nextCoursej);
            inDegree[nextCoursej]++;
        } 
        queue<int> q;
        vector<int> maxTime(n, 0);
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0) {
                q.push(i);
                maxTime[i] = time[i];
            }
        };
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j=0; j<next[cur].size(); j++) {
                int neighbor = next[cur][j];
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[cur]+time[neighbor]);
                inDegree[next[cur][j]]--;
                if(inDegree[next[cur][j]] == 0)
                    q.push(next[cur][j]);
            };
        };
        int ans = 0;
        for(int node = 0; node<n; node++)
            ans = max(ans, maxTime[node]);
        return ans;
    }
};