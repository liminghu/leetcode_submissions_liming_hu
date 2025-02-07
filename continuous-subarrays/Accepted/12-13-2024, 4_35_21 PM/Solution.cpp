// https://leetcode.com/problems/continuous-subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int j = 0; //left
        int i = 0;
        int curMin = 0;
        int curMax = 0;
        long long windowLen = 0;
        curMin = curMax = nums[0];
        for(; i<n; i++) {  //right
            curMin = min(curMin, nums[i]);
            curMax = max(curMax, nums[i]);
            if(curMax-curMin > 2) {
                windowLen = i-j;
                res += windowLen*(windowLen+1)/2;
                j = i;
                curMin = curMax = nums[i];
                while(j>0 && abs(nums[i]-nums[j-1])<=2) {
                    j--;
                    curMin = min(curMin, nums[j]);
                    curMax = max(curMax, nums[j]);
                }
                if(j<i) {
                    windowLen = i-j;
                    res -= (windowLen+1)*windowLen/2;
                }
            }
        };
        windowLen = i-j;
        res += (windowLen+1)*windowLen/2;
        return res;
    }
};