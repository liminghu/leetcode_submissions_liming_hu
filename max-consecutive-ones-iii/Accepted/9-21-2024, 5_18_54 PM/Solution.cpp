// https://leetcode.com/problems/max-consecutive-ones-iii

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's 
in the array if you can flip at most k 0's.
Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;
        int n = nums.size();
        int zeroCount = 0;
        int i=0;
        for(int j=0; j<n; j++) {
            if(nums[j] == 1) 
                ret = max(ret, j-i+1);
            else {
                zeroCount++;
                while(zeroCount > k) {
                    if(nums[i] == 0)
                        zeroCount--;
                    i++;
                }
                ret = max(ret, j-i+1);
            };
        } 
        return ret;
    }
};