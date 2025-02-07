// https://leetcode.com/problems/decode-ways-ii

using LL = long long;
class Solution {
    int M = 1e9+7;
public:
    int numDecodings(string s) {//s consisting of digits and '*' characters, return the number of ways to decode it.
        int n = s.length();
        vector<LL> dp(n+1, 0);

        dp[0] = 1;
        if(s[0]=='0') //invalid
            return 0;
        dp[1] = s[0]=='*'? 9: 1;

        for(int i=2; i<=n; i++) {
            char first = s[i-2];
            char second = s[i-1];
            if( second == '*' )
                dp[i] += 9 * dp[i-1];
            else if(second>'0')
                dp[i] += dp[i-1];
            
            if(first == '*') {
                if(second=='*')
                    dp[i] += 15*dp[i-2]; //9+6
                else if(second<='6')
                    dp[i] += 2*dp[i-2]; //1, 2
                else
                    dp[i]+= dp[i-2];
            } else if(first =='1' || first == '2') {
                if(second=='*') {
                    if(first=='1')
                        dp[i]+=9*dp[i-2];
                    else
                        dp[i]+=6*dp[i-2];
                } else if( (first-'0')*10+(second-'0')<=26 )
                    dp[i] +=dp[i-2];
            }
            dp[i]%=M;
        }
        return (int)dp[n];
        
    }
};