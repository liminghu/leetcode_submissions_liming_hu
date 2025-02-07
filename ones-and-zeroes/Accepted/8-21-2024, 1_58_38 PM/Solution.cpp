// https://leetcode.com/problems/ones-and-zeroes

/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*  1 <= strs.length <= 600
            1 <= strs[i].length <= 100
            strs[i] consists only of digits '0' and '1'.
            1 <= m, n <= 100
        */
        auto dp=vector<vector<int>>(m+1, vector<int>(n+1, 0)); //zeros, ones.
        auto temp = dp;
        for(int k=0; k<strs.size(); k++) {
            int zeros = 0;
            int ones = 0;
            for(auto x:strs[k]) {
                if(x=='0')
                    zeros++;
                else
                    ones++;
            };

            for(int i=zeros; i<=m; i++) 
                for(int j=ones; j<=n; j++) {
                    temp[i][j] = max(dp[i-zeros][j-ones]+1, dp[i][j]);
                };
            dp = temp;
        }

        return dp[m][n];
    }
};