// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) { // non-decreasing order
        int k = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]>nums[((i+1)%n)])
                k++;
            if(k>1)
                return false;
        }
        return true;
    }
};