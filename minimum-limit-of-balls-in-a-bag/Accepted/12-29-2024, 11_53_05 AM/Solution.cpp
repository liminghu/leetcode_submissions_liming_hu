// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi =*max_element(nums.begin(), nums.end());
        while(lo<hi) {
            int m = lo +(hi-lo)/2;
            int ops = 0;
            for(int num: nums) {
                ops+= (num-1)/m;
            }
            if(ops<=maxOperations)
                hi = m;
            else
                lo = m+1;
        }
        return lo;
    }
};