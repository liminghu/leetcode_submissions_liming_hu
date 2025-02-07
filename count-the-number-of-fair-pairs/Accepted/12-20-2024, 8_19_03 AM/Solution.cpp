// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // A pair (i, j) is fair if:
        // 0 <= i < j < n, and
        // lower <= nums[i] + nums[j] <= upper
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            //nums[j]<=upper-nums[i]
            auto up = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);
            auto down = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);
            ans += up-down;
        }
        return ans;
    }
};