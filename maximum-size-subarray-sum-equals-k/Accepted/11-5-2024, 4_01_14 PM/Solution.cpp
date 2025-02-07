// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int longest = 0;
        long long  prefixSum = 0;
        unordered_map<long long, int> mp; // key: prefixSum, value: index.
        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];
            if(prefixSum == k )
                longest = i+1;
            
            long long  diff = prefixSum - k;   
            if(mp.find(diff) != mp.end()) {
                longest = max(longest, i - mp[diff]);
            }  
            if(mp.find(prefixSum) == mp.end())
                mp[prefixSum] = i;
        }
        return longest;
    }
};