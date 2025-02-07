// https://leetcode.com/problems/maximum-balanced-subsequence-sum

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_i(n, 0);
        for(int i=0; i<n; i++)
            nums_i[i] = nums[i]-i;
        map<int, long long> dp;   //arr, maxBalancedSubsequenceSum
        long long ret = LLONG_MIN;
        for(int i=0; i<n; i++) {
            int x = nums_i[i];
            auto iter = dp.upper_bound(x);
            if(iter != dp.begin()) {
                iter = prev(iter);
                dp[x] = max((long long)nums[i], iter->second + nums[i]); //iter->second could be negative.
            } else 
                dp[x] = nums[i];
            ret = max(ret, dp[x]);
            iter = dp.find(x);
            iter = next(iter);
            while(iter!=dp.end() && iter->second <=dp[x]) 
                iter = dp.erase(iter);
        };
        return ret;
    }
};