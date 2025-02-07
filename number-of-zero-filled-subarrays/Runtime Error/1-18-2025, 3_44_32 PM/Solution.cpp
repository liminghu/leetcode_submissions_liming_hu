// https://leetcode.com/problems/number-of-zero-filled-subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //Given an integer array nums, return the number of subarrays filled with 0.
        int n = nums.size();
        long long ret = 0;
        int i=0;
        while(i<n) {
            if(nums[i]!=0) {
                i++;
                continue;
            };
            int j = i;
            while(j<n && nums[j]==0) {
                j++;
            };
            ret += (j-i)*(j-i+1)/2;
            i = j;
        }
        return ret;
    }
};