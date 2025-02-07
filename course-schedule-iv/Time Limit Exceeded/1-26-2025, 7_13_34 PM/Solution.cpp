// https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
        vector<vector<int>> next(numCourses);
        //queries[j] = [uj, vj]
        for(auto preq: prerequisites) {
            int ai = preq[0];
            int bi = preq[1];
            next[ai].push_back(bi);
        };
        int n = queries.size();
        vector<bool> ret(n, false);
        for(int i=0; i<n; i++) {
            int uj = queries[i][0];
            int vj = queries[i][1];
            queue<int> q;
            if(next[uj].size()==0)
                continue;
            for(int j=0; j<next[uj].size(); j++)
                q.push(next[uj][j]);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                if(cur == vj) {
                    ret[i] = true;
                    break;
                };
                for(int j=0; j<next[cur].size(); j++)
                    q.push(next[cur][j]);
            };
        }
        return ret;
    }
};