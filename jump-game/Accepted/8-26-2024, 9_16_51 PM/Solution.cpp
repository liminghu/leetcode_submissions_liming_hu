// https://leetcode.com/problems/jump-game

//You are given an integer array nums. You are initially positioned at the array's first index, 
//and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*  1 <= nums.length <= 104
            0 <= nums[i] <= 105
        */
        /*int n = nums.size();
        if(n<=1)
            return true;
        
        vector<bool> dp(n,false);
        dp[n-1] = true;
        for(int i=n-2; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(dp[j] == true && nums[i] + i >= j) {
                    dp[i] = true;
                    //cout << j << " dp[j] = " << dp[j] << endl;
                    break;
                }
            };
        }

        return dp[0];*/

        int lastPos = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--) {
            if(i+nums[i] >= lastPos) 
                lastPos = i;
        };

        return lastPos == 0;

    }
};