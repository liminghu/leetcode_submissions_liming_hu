// https://leetcode.com/problems/house-robber

class Solution {
public:
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money 
you can rob tonight without alerting the police.
*/
    int rob(vector<int>& nums) { //1 <= nums.length <= 100; 0 <= nums[i] <= 400
    //0: if I did not rob i;
    //1: if I robbed i.
        int sz = nums.size();
        vector<vector<int>> max_gain(sz, vector<int>(2,0));

        max_gain[0][0] = 0;
        max_gain[0][1] = nums[0];

        for(int i=1; i<sz; i++) {
            max_gain[i][0] = max(max_gain[i-1][0], max_gain[i-1][1]); //this iteration, I did not rob.
            max_gain[i][1] = max_gain[i-1][0]+nums[i]; //this iteration, I rob.
        };

        return max(max_gain[sz-1][0], max_gain[sz-1][1]);
        
    };

};