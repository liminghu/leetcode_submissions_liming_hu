// https://leetcode.com/problems/maximum-sum-circular-subarray

/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of 
nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], 
nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //the next element of nums[i] is nums[(i + 1) % n] and 
        //the previous element of nums[i] is nums[(i - 1 + n) % n]
        int n = nums.size();
        vector<int> dp_pos(n, 0); //dp[i]: the max subarray ending with i.
        dp_pos[0] = nums[0];
        for(int i=1; i<n; i++)
            dp_pos[i] = max(nums[i], nums[i] + dp_pos[i-1]);

        vector<int> dp_neg(n, 0); //dp[i]: the max subarray ending with i.
        dp_neg[0] = -nums[0];
        for(int i=1; i<n; i++)
            dp_neg[i] = max(-nums[i], -nums[i] + dp_neg[i-1]);
        
        int max_p = *max_element(dp_pos.begin(), dp_pos.end());
        int max_n = *max_element(dp_neg.begin(), dp_neg.end());
        if(max_p < 0)
            return max_p;
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        return max(max_p, sum+max_n);
    }
};