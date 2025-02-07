// https://leetcode.com/problems/minimum-operations-to-make-numbers-non-positive

class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        int left = 0;
        int right = INT_MAX/2;
        while(left<right) {
            int mid = left+(right-left)/2;
            if(isOK(mid, nums, x, y)) {
                right = mid;
            } else
                left = mid+1;
        }
        return left;
    }
    bool isOK(int mid, vector<int>& nums, int x, int y) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 1.0* mid * y)
                continue;
            count += ceil( (nums[i]-mid*1.0*y)/(x-y) );
            if(count > mid)
                return false;
        }
        return true;
    }
};