// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1)
            return 1;
        int maxBeauty = 0;
        int maxValue;
        for(int num:nums)
            maxValue = max(maxValue, num);
        vector<int> count(maxValue+1, 0);
        for(int num:nums) { //update the count array for each value's range [val-k, val+k]
            count[max(num-k, 0)]++; 
            if(num+k+1<maxValue)
                count[num+k+1]--; //decrement after the range.
        }
        int curSum = 0;
        for(int val:count) {
            curSum += val;
            maxBeauty = max(maxBeauty, curSum);
        };
        return maxBeauty;
    }
};