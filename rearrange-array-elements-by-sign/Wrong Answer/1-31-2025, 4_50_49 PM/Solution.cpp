// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       /*You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

        You should return the array of nums such that the the array follows the given conditions:

        Every consecutive pair of integers have opposite signs.
        For all integers with the same sign, the order in which they were present in nums is preserved.
        The rearranged array begins with a positive integer.
        Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
        */
        int n = nums.size();
        n = n/2;
        int pos_idx = 0;
        int neg_idx = 0;
        for(int i=0; i<n; i++) {
            while(pos_idx<2*n && nums[pos_idx]<0) 
                pos_idx++;
            while(neg_idx<2*n && nums[neg_idx]>0) 
                neg_idx++;

            if(nums[2*i]>0 && nums[2*i+1] < 0)
                continue;
            else if(nums[2*i]<0 && nums[2*i+1] > 0) {
                swap(nums[2*i], nums[2*i+1]);
                continue;
            } else if(nums[2*i]<0 && nums[2*i+1] < 0) {
                swap(nums[2*i], nums[pos_idx]);
                continue;               
            } else if(nums[2*i]>0 && nums[2*i+1] > 0) {
                swap(nums[2*i+1], nums[neg_idx]);
                continue;               
            }
        };
        return nums; 
    }
};