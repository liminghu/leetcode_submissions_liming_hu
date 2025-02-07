// https://leetcode.com/problems/string-compression-ii

class Solution {
    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int dp[105][105];
    string str;
    int n;
    inline int xs(int x) {
        return x==1? 0: x<10? 1: x<100? 2: 3;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {//1 <= s.length <= 100
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.length();
        return solve(0, k);
    }
    int solve(int left, int k) {
        if(k<0)
            return 105; //invalid
        if(left>=n || n-left<=k)
            return 0; //empty
        int& res = dp[left][k];
        if(res!=-1)
            return res;
        res = 105;
        int cnt[26] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)   
        for(int j=left, most = 0; j<n; j++) {
            most = max(most, ++cnt[str[j]-'a']); // most = max(count(s[left:j]))
            res = min(res, 1+xs(most)+solve(j+1, k-(j-left+1-most)));
        }     
        return res;
    }
};