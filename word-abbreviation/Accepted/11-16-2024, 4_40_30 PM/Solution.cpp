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
            for( int i=0; i < len; i++ ) {
                string cur_str = dict[ indices[i] ];
                for(int j= i+1; j < len; j++) {
                    int lcp_len = LCP( cur_str, dict[ indices[j] ] );
                    if(lcp_len > dp[i] ) 
                        dp[i] = lcp_len;
                    if(lcp_len > dp[j] )
                        dp[j] = lcp_len;
                }
                if(dp[i] >= cur_str.length() - 2)
                    ans[ indices[i] ] = cur_str;
                else {
                    string right = cur_str.substr( dp[i] );//start from dp[i] to end...
                    ans[ indices[i] ] = cur_str.substr(0, dp[i]) + abbreviate( right );
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
    //Check longest common prefix, and return LCP length
    int LCP(string& s1, string& s2 ) {
        if(s1.length() != s2.length())
            return 0;
        int i = 0;
        for(; i<s1.length(); i++) {
            if(s1[i] != s2[i])
                return i;
        }
        return i;
    }
};