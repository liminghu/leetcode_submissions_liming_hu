// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int cnt_i = 1;
        int cnt_d = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i])
                cnt_d++;
            else
                cnt_d = 1;
            if(nums[i-1] < nums[i])
                cnt_i++;
            else
                cnt_i = 1;
            res = max({res, cnt_i, cnt_d});
        }
        return res;
    }
};