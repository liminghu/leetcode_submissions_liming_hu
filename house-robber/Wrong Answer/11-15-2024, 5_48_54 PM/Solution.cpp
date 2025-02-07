// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       int robMoney = 0;
       int noRobMoney = 0;
       for(int i=0; i<n; i++) {
           int prevRobMoney = robMoney;
           robMoney = noRobMoney + nums[i];
           noRobMoney = prevRobMoney;
       };
       return max(robMoney, noRobMoney);
    }
};