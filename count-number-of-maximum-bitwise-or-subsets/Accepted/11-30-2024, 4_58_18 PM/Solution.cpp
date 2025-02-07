// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<long> dp(1<<17); //how many subsets whose bitwose or == val
        int max = 0;
        dp[0] = 1;
        for(int num: nums) {
            for(int i=max; i>=0; i--) {
                dp[ i | num ] += dp[i];
            };
            max |= num;
        }

        return dp[max];
    }
};