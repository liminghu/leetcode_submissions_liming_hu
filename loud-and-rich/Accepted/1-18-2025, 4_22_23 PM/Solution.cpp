// https://leetcode.com/problems/loud-and-rich

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //richer[i] = [ai, bi] indicates that ai has more money than bi
        int n = quiet.size();
        //answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) 
        //among all people who definitely have equal to or more money than the person x.
        vector<int> rets(n, -1);
        unordered_map<int, vector<int>> mpPoorer;
        vector<int> inDegree(n);
        for(auto a: richer) {
            mpPoorer[a[0]].push_back(a[1]);
            inDegree[a[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0)
                q.push(i);
            rets[i] = i;
        };
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int nxt: mpPoorer[cur]) {
                if(quiet[rets[nxt]] > quiet[rets[cur]])
                    rets[nxt] = rets[cur];
                inDegree[nxt]--;
                if(inDegree[nxt] == 0)
                    q.push(nxt);
            }
        }
        return rets;
    }
 
};