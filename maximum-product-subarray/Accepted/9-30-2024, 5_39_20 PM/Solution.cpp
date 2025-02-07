// https://leetcode.com/problems/maximum-product-subarray

/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,0); // the max prod subarray ending at i 
        vector<int> dp2(n,0); // the min prod subarray ending at i 
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        int ret = nums[0];
        for(int i=1; i<n; i++) {
            dp1[i] = max( max(dp1[i-1]* nums[i], dp2[i-1]* nums[i]), nums[i]);
            dp2[i] = min( min(dp1[i-1]* nums[i], dp2[i-1]* nums[i]), nums[i]);
            ret = max(ret, dp1[i]);
        } ;
        return ret;
    }
};