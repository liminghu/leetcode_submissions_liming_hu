// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int cur_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            cur_sum += nums[i];
            ans.push_back(cur_sum);
        };
        return ans;
        
    }
};