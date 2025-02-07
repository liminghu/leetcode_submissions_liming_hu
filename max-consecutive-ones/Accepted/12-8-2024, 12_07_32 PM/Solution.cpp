// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int i = 0;
        while(i<n) {
            if(nums[i]== 0) {
                i++;
                continue;
            }
            int j = i;
            while(j<n && nums[j] ==1)
                j++;
            ret = max(ret, j-i);
            i=j;
        };
        return ret;
    }
};