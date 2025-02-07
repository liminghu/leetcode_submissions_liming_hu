// https://leetcode.com/problems/rank-teams-by-votes

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> freq(26, vector<int>(n)); // "A"~"Z"
        if(n==1)
            return votes[0];
        
        string ans = votes[0]; //initialize.

        for(auto vote:votes) {
            for(int j=0; j<n; j++) {
                freq[vote[j]-'A'][j]++;
            }
        }

        sort(ans.begin(), ans.end(), [&](auto&x, auto&y) 
            {
                if(freq[x-'A'] == freq[y-'A']) //all the votes' freq are the same.
                    return x<y; 
                return freq[x-'A'] > freq[y-'A']; //compare these two vectors. 
            } 
        );

        return ans;

        
    }
};