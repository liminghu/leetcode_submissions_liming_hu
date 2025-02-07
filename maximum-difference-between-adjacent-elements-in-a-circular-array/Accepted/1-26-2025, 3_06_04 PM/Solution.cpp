// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            ret = max(ret, abs(nums[i]-nums[(i-1+n)%n]));
        }
        return ret;
    }
};