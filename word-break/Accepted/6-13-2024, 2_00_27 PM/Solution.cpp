// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(int i=0; i<wordDict.size(); i++) {
            dict[wordDict[i]] = true;
        };

        int sz = s.length();
        vector<int> dp_wb_str_i(sz+1, 0);
        dp_wb_str_i[0] = 1;
        
        for(int i=1; i<=sz; i++ ) {            //str until i, at least one char.
            //break point: suppose after the break point, it is one word. 
            for(int b=0; b<i; b++) {
                string sub = s.substr(b, i-b);
                if( dict.find(sub) != dict.end() )  {//found
                    dp_wb_str_i[i] = max(dp_wb_str_i[i], dp_wb_str_i[b]);  
                }
            }
        }

        return dp_wb_str_i[sz]==1; 
        
    }
};