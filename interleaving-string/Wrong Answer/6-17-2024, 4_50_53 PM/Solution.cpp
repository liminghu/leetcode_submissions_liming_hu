// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.length();
        int sz2 = s2.length();
        int sz3 = s3.length();
        
        if(sz1+sz2!=sz3)
            return false;
        if(sz1==0)
            return s2==s3;
        if(sz2==0)
            return s1==s3;
        
        
        //dp
        vector<vector<bool>> dp(sz2+1, vector<bool>(sz1+1, false)  );
        
        dp[0][0] = true;
        for(int i=1; i<sz1+1; i++) {
            if(dp[0][i-1]==true && s1[i-1]==s3[i-1])
                dp[0][i]= true;
        };
        
        for(int j=1; j<sz2+1; j++) {
            if(dp[j-1][0]==true && s2[j-1]==s3[j-1])
                dp[j][0]= true;
        };
        
        for(int i=1; i<sz1+1; i++) {
            for(int j=1; j<sz2+1; j++) {        

                if(dp[i-1][j] && s1[i-1]==s3[i+j-1])
                    dp[j][i] = true;
                if(dp[i][j-1] && s2[j-1]==s3[i+j-1])
                    dp[j][i] = true;
            }
        }
        
        return dp[sz2][sz1];
                    
        
    }
};