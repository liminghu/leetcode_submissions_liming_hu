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
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> presum(n+1, 0);
        presum[0] = 0;
        for(int i=0; i<n; i++)
            presum[i+1] = presum[i] + nums[i];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int subsum_i_j = 0;
                if(j>=i) {
                    subsum_i_j = presum[j+1]-presum[i];
                } else { //j<i
                    if( j+1 < i)
                        subsum_i_j = presum[n]-(presum[i]- presum[j+1]);
                    else
                        subsum_i_j = presum[n];
                }
                ans = max(ans, subsum_i_j);
            }
        }
        return ans;
    }
};