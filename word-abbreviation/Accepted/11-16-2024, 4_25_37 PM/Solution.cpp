// https://leetcode.com/problems/word-abbreviation

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ans(n, "");
        unordered_map<string, vector<int>> abbrevs;
        for(int i=0; i<n; i++) {
            string abbrev = abbreviate(dict[i]);
            abbrevs[abbrev].push_back(i);
            ans[i] = abbrev;
        };
        //check duplicates.
        for(auto& words: abbrevs) {
            if(words.second.size() < 2)
                continue;
            //handle conflicts
            auto& indices = words.second;
            int len = indices.size();
            //use a DP vector to avoid recompute of LCP bewtween two words.
            vector<int> dp(len, 0);
            for(int i=0; i<len; i++) {
                string cur_str = dict[indices[i]];
                for(int j=i+1; j<len; j++) {
                    int sim = LCP(cur_str, dict[indices[j]]);
                    if(sim>dp[i]) 
                        dp[i] = sim;
                    if(sim>dp[j])
                        dp[j] = sim;
                }
                if(dp[i] >= cur_str.length() - 2)
                    ans[indices[i]] = cur_str;
                else {
                    string left = cur_str.substr(dp[i]);
                    ans[indices[i]] = cur_str.substr(0, dp[i]) + abbreviate(left);
                }
            }
        }
        return ans;

    }
    string abbreviate(string& str) {
        if(str.length()<=3)
            return str;
        return str[0] + to_string(str.size()-2)+str.back();
    }
    int LCP(string& s1, string& s2 ) {
        if(s1.length() != s2.length())
            return 0;
        int i=0;
        for(; i<s1.length(); i++) {
            if(s1[i]!=s2[i])
                return i;
        }
        return i;
    }
};