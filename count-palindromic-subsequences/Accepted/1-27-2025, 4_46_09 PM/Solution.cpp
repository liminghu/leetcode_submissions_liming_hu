// https://leetcode.com/problems/count-palindromic-subsequences

class Solution {
    int M = 1e9+7;
public:
    int countPalindromes(string s) { //s consists of digits.
        //palindromic subsequences of s having length 5
        int n = s.length();
        long long ans = 0;
        for(int x =0; x<=9; x++) {
            for(int y=0; y<=9; y++) {
                vector<int> pattern = {x,y, 0, y, x};
                vector<long long> dp(6);
                dp[5] = 1;
                for(int i=0; i<n; i++) {
                    for(int j=0; j<5; j++) {
                        if(s[i]==pattern[j]+'0' || j==2)
                            dp[j] = (dp[j]+dp[j+1])%M;
                    }
                }
                ans = (ans+dp[0])%M;
            }
        }
        return ans;

    }
};