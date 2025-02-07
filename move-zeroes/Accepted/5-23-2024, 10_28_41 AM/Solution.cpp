// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) { //time complexity: o(n), space: o(1)
        //[0,1,0,3,12]
        if(nums.size() <=1) //[], [0], [2]
            return;
        //Input: nums = [0,1,0,3,12]
        //scan from beginning, if non zero continue. if 0, swap with the closest non zero. unitl the end.

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] != 0)
                continue;
            //current elmenet is 0.
            int j = i+1;
            for(; j<nums.size(); j++) {
                if(nums[j] != 0)
                    break;
            }
            if(j==nums.size() && nums[j-1]==0)   //to the end, all zeros.
                return;
            //find an element which is non zero.
            swap(nums[i], nums[j]);
        }

        return;
        
    }
};