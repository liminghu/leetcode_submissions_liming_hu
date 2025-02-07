// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int score = 0;
        int numMax = nums[0];   //
        int numMin = nums[0];
        for(int i=0; i<nums.size(); i++) {
            numMax = max(numMax, nums[i]);
            numMin = min(numMin, nums[i]);
        };
        if(numMax-k > (numMin+k))
            return numMax-k - (numMin+k);
        else
            return 0;

    }
};