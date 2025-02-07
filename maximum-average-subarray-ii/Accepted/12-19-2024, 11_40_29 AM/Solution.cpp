// https://leetcode.com/problems/maximum-average-subarray-ii

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //Find a contiguous subarray whose length is greater than or equal to k that has the maximum average value
        // and return this value. Any answer with a calculation error less than 10-5 will be accepted.
        double right = INT_MIN;
        double left = INT_MAX;
        for(auto num: nums) {
            right = fmax(right, num);
            left = fmin(left, num);
        };

        while( right-left > 1e-5 ) {
            double mid = (right+left)*0.5;
            if(check(nums, mid, k))
                left = mid;
            else
                right = mid;
        }
        return left;
    }
    bool check(vector<int>& nums, double mid, int k) {
        double curSum = 0;
        double prevSum = 0;
        double minSum = 0;
        for(int i=0; i<nums.size(); i++) {
            curSum += nums[i]-mid;
            if(i>=k-1) {
                if( curSum-minSum >= 0)
                    return true;
                prevSum += nums[i-k+1]-mid;
                minSum = min(prevSum, minSum);
            }
        } 
        return false;   
    }
};