// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

/*
You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums 
after performing at most three moves.
*/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 4)
            return 0;
        
        sort(nums.begin(), nums.end());

        return min( min(nums[sz-4]-nums[0], nums[sz-1]-nums[3]),
                    min(nums[sz-2]-nums[2], nums[sz-3]-nums[1]));
        
    }
};