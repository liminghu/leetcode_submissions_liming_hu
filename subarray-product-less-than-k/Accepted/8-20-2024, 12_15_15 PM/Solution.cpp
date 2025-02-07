// https://leetcode.com/problems/subarray-product-less-than-k

//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
            1 <= nums.length <= 3 * 104
            1 <= nums[i] <= 1000
            0 <= k <= 106
        */
        if(k<=1)
            return 0;
        
        int j = 0;
        int prod = 1;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(j<i) {
                j=i;
                prod = 1;
            };

            while(j<nums.size() && prod*nums[j]<k) {
                prod = prod*nums[j];
                j++;
            }
            count += j-i; //open
            prod = prod/nums[i]; 
        }
        return count;
    }
};