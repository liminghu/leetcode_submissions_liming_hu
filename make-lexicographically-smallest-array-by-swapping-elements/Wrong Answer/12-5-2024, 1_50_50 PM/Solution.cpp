// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++)
            if( nums[j] < nums[i] && abs(nums[i]-nums[j])<=limit ) {
                swap(nums[i], nums[j]);
            };
        }
        return nums;
    }
};