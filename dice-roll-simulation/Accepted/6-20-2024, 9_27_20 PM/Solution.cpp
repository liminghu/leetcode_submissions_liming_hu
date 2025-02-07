// https://leetcode.com/problems/dice-roll-simulation

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
      
        int M = 1e9+7;        
        auto dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(7,vector<int>(16,0)));
        rollMax.insert(rollMax.begin(),0);

        for (int j=1; j<=6; j++)
            dp[1][j][1] = 1;

        for (int i=2; i<=n; i++)
            for (int j=1; j<=6; j++)
                for (int k=1; k<=rollMax[j]; k++)
                {
                    if (k==1)
                    {
                        for (int jj=1; jj<=6; jj++)
                        {
                            if (jj==j) continue;
                            for (int kk=1; kk<=rollMax[jj]; kk++)
                                dp[i][j][k] = (dp[i][j][k] + dp[i-1][jj][kk])%M;
                        }
                    }
                    else
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%M;
                    }
                }
    
        int sum = 0;
        for (int j=1; j<=6; j++)
            for (int k=1; k<=rollMax[j]; k++)
                sum = (sum + dp[n][j][k])%M;

        return sum;

        
        //dp[i][j][k] = 
    
//dp[i][6][1] = sum(dp[i-1][1][?] .... dp[i-1][5][?] )   excluding dp[i-1][6][?]
        
        /*
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(16,0)));
        
      
        int M = 1e9+7;        
        rollMax.insert(rollMax.begin(), 0);
        
        for(int j=1; j<=6; j++)
            dp[1][j][1] = 1;
        
        for(int i=2; i<=n; i++) {
             for(int j=1; i<=6; j++) {
                 for(int k=1; k<=rollMax[j]; k++) {
                     //dp[i][6][2] = dp[i-1][6][1]
                     if(k==1) {                   
                         //dp[i][6][1] = sum(dp[i-1][1][?] .... dp[i-1][5][?] )   excluding dp[i-1][6][?]
                         for(int jj=1; jj<=6; jj++) {
                             if(jj == j) 
                                 continue;
                         
                             for(int kk=1; kk<=rollMax[jj]; kk++) {                                 
                                    dp[i][j][k] = ( dp[i][j][k] + dp[i-1][jj][kk] ) % M;                                
                             }   
                         }
                     } else {
                          dp[i][j][k] = ( dp[i][j][k] + dp[i-1][j][k-1] ) % M;
                     } //else
                 }   //k     
            } //j
        } //i
        
        int ret = 0;   
        for(int j=1; j<=6; j++) {
            for(int k=1; k<=rollMax[j]; k++) {
                ret = ( ret + dp[n][j][k] )% M;
            }
        }
    
        return ret;  */  
    }
};

//6^n

//paint house: dp[i][j] = sum(dp[i-1][j']) j'!=j

//i: ith times, j: 0..6. k: continous time.
//dp[i][j][k] = 
    
//dp[i][6][2] = dp[i-1][6][1]


//dp[i][6][1] = sum(dp[i-1][1][?] .... dp[i-1][5][?] )   excluding dp[i-1][6][?]
