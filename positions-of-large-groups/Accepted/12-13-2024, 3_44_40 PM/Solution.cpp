// https://leetcode.com/problems/positions-of-large-groups

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> rets;
        int n = s.length();
        int i = 0;
        int j = 0;
        while(i<n) {
            j = i;
            while(j<n && s[i]==s[j])
                j++;
            if(j-i>=3)
                rets.push_back({i, j-1});
            i = j;
        };
        return rets;
    }
};