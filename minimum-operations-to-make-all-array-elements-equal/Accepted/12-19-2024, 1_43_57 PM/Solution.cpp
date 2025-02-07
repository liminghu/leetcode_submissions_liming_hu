// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal

using LL = long long;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<LL> rets(m, 0);
        vector<LL> prefix(n+1);
        for(int i=0; i<n; i++)
            prefix[i+1] = prefix[i] +(LL)nums[i];
        for(int j=0; j<m; j++) {
            int num_idx = lower_bound(nums.begin(), nums.end(), queries[j])-nums.begin();
            rets[j] = (LL)queries[j] * (2*num_idx-n) + (prefix[n]-2*prefix[num_idx]);
        }
        return rets;
    }
};