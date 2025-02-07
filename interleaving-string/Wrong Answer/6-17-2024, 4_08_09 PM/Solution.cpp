// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) { //0 <= s1.length, s2.length <= 100; 0 <= s3.length <= 200; s1, s2, and s3 consist of lowercase English letters.
        int sz1= s1.length();
        int sz2 = s2.length();
        int sz3 = s3.length();
        
        if(sz1+sz2!=sz3)
            return false;
        if(sz1==0)
            return s2==s3;
        if(sz2==0)
            return s1==s3;
        
        
        //dp
        vector<vector<unordered_set<string>>> dp(sz2+1, vector<unordered_set<string>>(sz1+1, unordered_set<string>())  );
        
        dp[0][0].insert("");
        for(int i=1; i<sz1+1; i++) {
            dp[0][i].insert(s1.substr(0, i));
        };
        
        for(int j=1; j<sz2+1; j++) {
            dp[j][0].insert(s2.substr(0, j));
        };
        
        for(int i=1; i<sz1; i++) {
            for(int j=1; j<sz2; j++) {
                unordered_set<string> temp;
                
                unordered_set<string> temp_i1_j1 =dp[j-1][i-1];  //s1[i]    s2[j]
                for(unordered_set<string>::iterator k=temp_i1_j1.begin(); k!=temp_i1_j1.end(); k++) {
                    temp.insert(*k+s1[i]+s2[j]);                    
                    temp.insert(*k+s2[j]+s1[i]);
                }
                
                
                unordered_set<string> temp_i1 = dp[j][i-1];   //s1[i]
                for(unordered_set<string>::iterator k=temp_i1.begin(); k!=temp_i1.end(); k++) {                   
                    temp.insert(*k+s1[i]);
                }
                
                unordered_set<string> temp_j1 = dp[j-1][i];   //s2[j]
                for(unordered_set<string>::iterator k=temp_j1.begin(); k!=temp_j1.end(); k++) {                   
                    temp.insert(*k+s2[j]);
                }
                
                dp[j][i] = temp;
            }
        }
        
        return dp[sz2][sz1].find(s3)!=dp[sz2][sz1].end();
                    
        
    }
};