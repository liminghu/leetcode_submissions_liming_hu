// https://leetcode.com/problems/find-pivot-index

/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        leftSum[0] = 0;
        vector<int> rightSum(n, 0);     
        rightSum[n-1] = 0;

        for(int i=1; i<n; i++) {
            leftSum[i] = leftSum[i-1]+nums[i-1];
        };
        for(int i=n-2; i>=0; i--) {
             rightSum[i] = rightSum[i+1]+nums[i+1];
        };

        for(int i=0; i<n; i++) {
            if(leftSum[i] == rightSum[i])
                return i;
        };
        return -1;  
    }
};