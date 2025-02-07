// https://leetcode.com/problems/count-partitions-with-even-sum-difference

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            preSum[i] = preSum[i-1]+nums[i];
        };
        int ret = 0;
        for(int i=0; i<n-1; i++) {
            int left = preSum[i];
            int right = preSum[n-1]-preSum[i];
            if(left%2==right%2)
                ret++;
        };
        return ret;
    }
};