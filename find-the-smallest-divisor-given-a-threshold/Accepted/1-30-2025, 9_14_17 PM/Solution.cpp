// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
        int ans = 0;
        int low = 1;
        int high = 1000000;
        while(low<=high) {
            int mid = (low+high)/2;
            int result = findDivisionSum(nums, mid);
            if(result <= threshold) {
                ans = mid;
                high = mid-1;
            } else
                low = mid+1;
        }
        return ans;
    }
    int findDivisionSum(vector<int>& nums, int divisor) {
        int res = 0;
        for(int num: nums) {
            res += ceil(1.0*num/divisor);
        };
        return res;
    }
};