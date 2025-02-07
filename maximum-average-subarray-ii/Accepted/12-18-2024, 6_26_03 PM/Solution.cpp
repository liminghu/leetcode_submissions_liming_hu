// https://leetcode.com/problems/maximum-average-subarray-ii

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //Find a contiguous subarray whose length is greater than or equal to k that has the maximum average value
        // and return this value. Any answer with a calculation error less than 10-5 will be accepted.
        double maxNum = INT_MIN;
        double minNum = INT_MAX;
        for(auto num: nums) {
            maxNum = fmax(maxNum, num);
            minNum = fmin(minNum, num);
        };
        double prevMid = maxNum;
        double error = INT_MAX;
        while(error>0.00001) {
            double mid = (maxNum+minNum)*0.5;
            if(check(nums, mid, k))
                minNum = mid;
            else
                maxNum = mid;
            error = fabs(prevMid-mid);
            prevMid = mid;
        }
        return minNum;
    }
    bool check(vector<int>& nums, double mid, int k) {
        double sum = 0;
        double prev = 0;
        double minSum = 0;
        for(int i=0; i<k; i++)
            sum+= nums[i]-mid;
        if(sum>=0)
            return true;
        for(int i=k; i<nums.size(); i++) {
            sum+= nums[i]-mid;
            prev += nums[i-k]-mid;
            minSum = min(prev, minSum);
            if(sum>=minSum)
                return true;
        } 
        return false;   

    }
};