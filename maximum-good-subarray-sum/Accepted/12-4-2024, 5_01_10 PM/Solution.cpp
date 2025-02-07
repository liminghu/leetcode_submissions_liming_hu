// https://leetcode.com/problems/maximum-good-subarray-sum

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = LONG_MIN;
        unordered_map<int, int> mp;
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) 
            prefixSum[i] = prefixSum[i-1]+nums[i];
        mp[nums[0]] = 0;
        for(int i=1; i<n; i++) {
            long long target1 = nums[i] + k;
            long long target2 = nums[i] - k;
            if(mp.find(target1)!=mp.end()) {
                long long curSum = prefixSum[i]-prefixSum[ mp[target1] ] + nums[ mp[target1] ];//mp[target1] < i
                maxSum = max(maxSum, curSum);
            }
            if(mp.find(target2)!=mp.end()) {
                long long curSum = prefixSum[i]-prefixSum[ mp[target2] ] + nums[ mp[target2] ];
                maxSum = max(maxSum, curSum);
            } 
            if(mp.find(nums[i])!=mp.end()) {
                if(prefixSum[i] >= prefixSum[mp[nums[i]]]) //too big, no need to update.
                    continue;
            }            
            mp[nums[i]] = i;
        }
        if(maxSum==LONG_MIN)    
            return 0;
        return maxSum;
    }
};