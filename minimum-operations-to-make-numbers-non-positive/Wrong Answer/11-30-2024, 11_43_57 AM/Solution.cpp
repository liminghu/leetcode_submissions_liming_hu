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
        float xydiff = x-y;
        for(int i=0; i<nums.size(); i++) {
            float num_diff = (nums[i]-mid*1.0*y); 
            if(num_diff <=0)
                continue;
            count += ceil( num_diff/xydiff );
            if(count > mid)
                return false;
        }
        return true;
    }
};