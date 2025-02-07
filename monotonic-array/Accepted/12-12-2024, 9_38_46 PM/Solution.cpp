// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        for(int i=1; i<nums.size(); i++) {
            inc &= (nums[i-1] <= nums[i]);
            dec &= (nums[i-1] >= nums[i]);
        };
        return inc || dec;
    }
};