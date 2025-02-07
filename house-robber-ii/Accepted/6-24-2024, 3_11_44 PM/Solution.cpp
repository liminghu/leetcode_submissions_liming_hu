// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two 
adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money 
you can rob tonight without alerting the police.
*/
    int rob(vector<int>& nums) { //1 <= nums.length <= 100; 0 <= nums[i] <= 1000
        int sz = nums.size();
        if(sz ==1)
            return nums[0];
        vector<vector<int>> max_gain(sz, vector<int>(2,0));
        
        max_gain[0][1] = nums[0];

        max_gain[0][0] = 0; //we did not rob the 0th house.
        max_gain[0][1] = 0;
        for(int i=1; i<sz; i++) {
            max_gain[i][0] = max(max_gain[i-1][0], max_gain[i-1][1]);
            max_gain[i][1] = max_gain[i-1][0] + nums[i];
        }

        int max_first = max(max_gain[sz-1][0], max_gain[sz-1][1]);

        max_gain.clear();
        max_gain = vector<vector<int>>(sz, vector<int>(2,0));
        //we did not rob the last house.
        max_gain[sz-1][0] = 0; //we did not rob the sz-1th house.
        max_gain[sz-1][1] = 0;
        for(int i=sz-2; i>=0; i--) {
            max_gain[i][0] = max(max_gain[i+1][0], max_gain[i+1][1]);
            max_gain[i][1] = max_gain[i+1][0] + nums[i];
        }

        int max_second = max(max_gain[0][0], max_gain[0][1]);

        return max(max_first, max_second);


    }
};