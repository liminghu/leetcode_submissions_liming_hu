// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums

/*
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array 
and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer 
can be a huge number return it modulo 109 + 7.
*/
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        /*  n == nums.length
            1 <= nums.length <= 1000
            1 <= nums[i] <= 100
            1 <= left <= right <= n * (n + 1) / 2
        */
        vector<int> sum; //(n*(n+1)/2, 0);
        for(int i=0; i<n; i++) {
            int s = 0;
            for(int j=i; j<n; j++) {
                s += nums[j];
                sum.push_back(s);
            }
        }
        sort(sum.begin(), sum.end());

        int res = 0;
        for(int i=left-1; i<=right-1; i++) {
            res = (res+sum[i]) % (1000000007);
        }
        return res;
    }
};