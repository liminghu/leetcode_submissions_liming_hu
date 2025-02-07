// https://leetcode.com/problems/product-of-array-except-self

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            2 <= nums.length <= 105
            -30 <= nums[i] <= 30
            The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
        */
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = 1;
        vector<int> suffix(n,0);
        suffix[n-1] = 1;

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1]; //nums[n-1] is excluded.
        };
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        };

        vector<int> res;
        for(int i=0; i<n; i++) {
            int temp = 0;
            temp = (prefix[i] * suffix[i]);
            res.push_back(temp);
        }
        return res;
    }
};