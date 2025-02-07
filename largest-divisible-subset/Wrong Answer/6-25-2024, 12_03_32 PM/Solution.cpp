// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/
    vector<int> largestDivisibleSubset(vector<int>& nums) {//1 <= nums.length <= 1000; 1 <= nums[i] <= 2 * 109; All the integers in nums are unique.
        sort(nums.begin(), nums.end());
        int sz = nums.size();

        if(sz == 1)
            return nums;

        vector<int> dp(sz, 1);
        vector<vector<int>> max_subset(sz, vector<int>());
        
       for(int i=0; i<sz; i++) 
            max_subset[i] = {nums[i]};
        
        for(int i=1; i<sz; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j]==0) {
                    dp[i] = max(dp[i], dp[j]+1);
                    max_subset[i] = max_subset[j];
                    max_subset[i].push_back(nums[i]);
                } 
            }
        }

        int max_length = 0;
        int index = 0;
        for(int i=0; i<sz; i++) {
            if(dp[i]> max_length) {
                index = i;
                max_length = dp[i];
            };
        }

        return max_subset[index];
         
    }
};