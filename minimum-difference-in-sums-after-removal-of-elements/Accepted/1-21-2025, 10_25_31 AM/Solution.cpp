// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) { //0-indexed integer array nums consisting of 3 * n elements.
        int n = nums.size()/3;
        //Return the minimum difference possible between the sums of the two parts after the removal of n elements.
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<>> right;
        long long leftSum = 0ll, rightSum = 0ll;
        long long ans = LLONG_MAX;
        vector<long long> maxSumRight(3*n);
        for(int i=3*n-1; i>=n; i--) {
            right.push(nums[i]);
            rightSum += nums[i];
            if(right.size()>n) {
                rightSum -= right.top();
                right.pop();
            };
            if(right.size()==n)
                maxSumRight[i] = rightSum; //maxSumRight[i] is the maximum sum of n digits in 'nums[i:]'.
        };
        for(int i=0; i<2*n; i++) {
            left.push(nums[i]);
            leftSum += nums[i];
            if(left.size()>n) {
                leftSum -= left.top();
                left.pop();
            };
            if(left.size()==n) //leftSum: the min sum of n digits in nums[0: i]
                ans = min(ans, leftSum-maxSumRight[i+1]);
        };
        return ans;
    }
};