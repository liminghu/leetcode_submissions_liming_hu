// https://leetcode.com/problems/house-robber-iv

/*
There are several consecutive houses along a street, each of which has some money inside. There is also a robber, 
who wants to steal money from the homes, but he refuses to steal from adjacent homes.
The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
You are given an integer array nums representing how much money is stashed in each house. More formally, the ith 
house from the left has nums[i] dollars.
You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always 
possible to steal at least k houses.
Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= (nums.length + 1)/2
*/
class Solution {
    //0: how many housese we can rob if we do not rob the ith house.
    //1: how many housese we can rob if we rob the ith house.
    int dp[100005][2]; 
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 0;
        int right = INT_MAX;
        while(left < right) {
            int mid = left+(right-left)/2;
            if( atLeastK(mid, nums, k) ) 
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    bool atLeastK(int cap, vector<int>& nums, int k) {
        int n = nums.size();
        dp[0][0] = 0; 
        if(nums[0] <=cap) 
            dp[0][1] = 1;
        else
            dp[0][1] = INT_MIN;

        for(int i=1; i<n; i++) {
            if(nums[i] > cap) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = INT_MIN; 
            } else {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + 1;                
            }
        }

        return max(dp[n-1][0], dp[n-1][1]) >= k;
    }
};