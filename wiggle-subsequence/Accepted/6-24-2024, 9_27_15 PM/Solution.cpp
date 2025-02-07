// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate
 between positive and negative. The first difference (if one exists) may be either positive or negative. 
 A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences
 A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the 
 remaining elements in their original order.
Given an integer array nums, return the length of the longest wiggle subsequence of nums.
*/
    int wiggleMaxLength(vector<int>& nums) { //1 <= nums.length <= 1000
        int sz = nums.size();
        //edge cases:
        if(sz == 1)
            return 1;
        if(sz ==2 && nums[0]!= nums[1])
            return 2;
        if(sz ==2 && nums[0]== nums[1])
            return 1;

        //at least 3 elements.
        vector<int> up(sz, 0); //以当前元素结尾且上升的 最长wiggle pattern 
        vector<int> down(sz,0); //以当前元素结尾且下降的 最长wiggle pattern 

        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<sz; i++) {
            if(nums[i]>nums[i-1]) { //If nums[i]>nums[i−1] that means it wiggles up. The element before it must be a down position. 
                                    //So up[i]=down[i−1]+1, down[i] remains the same as down[i−1].
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            } else if(nums[i]<nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1]+1;
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[sz-1], down[sz-1]);        
    }
};