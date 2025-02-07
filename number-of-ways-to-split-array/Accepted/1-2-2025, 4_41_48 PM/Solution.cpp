// https://leetcode.com/problems/number-of-ways-to-split-array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1]+nums[i];
        int ret = 0;
        for(int i=0; i<n-1; i++) {
            long rightSum = prefix[n-1]-prefix[i];
            long leftSum = prefix[i];
            if(leftSum>=rightSum)
                ret++; 
        }
        return ret;
    }
};