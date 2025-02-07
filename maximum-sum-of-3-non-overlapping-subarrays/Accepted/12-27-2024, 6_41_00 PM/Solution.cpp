// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        for(int i=0; i<n; i++) 
            preSum[i] = ( i==0? 0: preSum[i-1] ) + nums[i];
        vector<int> leftMax(n, 0);
        vector<int> leftIdx(n, 0);
        int maxSum = 0;
        int maxIdx = 0;
        for(int i=k-1; i<n; i++) {
            //[i-k+1, i]
            int sum = preSum[i] - (i<k?0:preSum[i-k]);
            if( sum > maxSum ) {
                maxSum = sum;
                maxIdx = i-k+1;
            }
            leftMax[i] = maxSum;
            leftIdx[i] = maxIdx;
        };
        vector<int> rightMax(n, 0);
        vector<int> rightIdx(n, 0);
        maxSum = 0;
        maxIdx = 0;
        for(int i=n-k; i>=0; i--) {
            //[i, i+k-1]
            int sum = preSum[i+k-1] - (i==0?0:preSum[i-1]);
            if( sum >= maxSum ) {
                maxSum = sum;
                maxIdx = i;
            }
            rightMax[i] = maxSum;
            rightIdx[i] = maxIdx;
        };      
        vector<int> idx;
        int ret = 0;
        for(int i=k; i+2*k<=n; i++) {
            //[i, i+k-1]
            int sum = preSum[i+k-1] - preSum[i-1];
            if(sum+leftMax[i-1]+rightMax[i+k] > ret) {
                ret = sum + leftMax[i-1] + rightMax[i+k];
                idx = {leftIdx[i-1], i, rightIdx[i+k]};
            }
        } 
        return idx; 
    }
};