// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if( nums[i] < nums[i-1] && abs(nums[i]-nums[i-1])<=limit ) {
                swap(nums[i], nums[i-1]);
            };
        }
        return nums;
    }
};