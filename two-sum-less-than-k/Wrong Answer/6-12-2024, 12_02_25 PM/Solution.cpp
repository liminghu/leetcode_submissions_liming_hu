// https://leetcode.com/problems/two-sum-less-than-k

class Solution {
public:
    /* Given an array nums of integers and integer k, return the maximum sum such that there exists 
       i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.
    */
    int twoSumLessThanK(vector<int>& nums, int k) { //1 <= nums[i] <= 1000 1 <= nums.length <= 100 1 <= k <= 2000
        
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int max_sum = -1;
        for(int i=0; i<sz; i++) {
            if(nums[i]>=k)
                continue;
            
            auto idx = upper_bound(nums.begin(), nums.end(), k-nums[i])-1;
            if(idx > nums.begin() + i)
                max_sum = max(max_sum, nums[i]+nums[idx-nums.begin()]);
        }
        
        return max_sum;
        
    }
};