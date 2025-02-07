// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<r) {
            if(nums[l]+nums[r]<target) {
                count += r-l;
                l++;
            } else
                r--;
        }
        return count;
    }
};