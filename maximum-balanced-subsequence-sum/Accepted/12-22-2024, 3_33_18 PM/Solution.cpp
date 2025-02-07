// https://leetcode.com/problems/maximum-balanced-subsequence-sum

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        /*
            A subsequence of nums having length k and consisting of indices i0 < i1 < ... < ik-1 is balanced if the following holds:
            nums[ij] - nums[ij-1] >= ij - ij-1, for every j in the range [1, k - 1].
         */
        int n = nums.size();
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++)
            arr[i] = nums[i]-i;
        map<int, long long> dp;   //arr, maxBalancedSubsequenceSum
        long long ret = LLONG_MIN;
        for(int i=0; i<n; i++) {
            int x = arr[i];
            auto iter = dp.upper_bound(x);
            if(iter != dp.begin()) {
                iter = prev(iter);
                dp[x] = max((long long)nums[i], iter->second + nums[i]); //iter->second could be negative.
            } else {
                dp[x] = nums[i];
            };
            ret = max(ret, dp[x]);
            iter = dp.find(x);
            iter = next(iter);
            while(iter!=dp.end() && iter->second <=dp[x]) {
                iter = dp.erase(iter);
            };
        };
        return ret;
    }
};