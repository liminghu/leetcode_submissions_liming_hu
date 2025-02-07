// https://leetcode.com/problems/continuous-subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int i=0; i<n; i++) {
            int j=i;
            while(j<n && abs(nums[j]-nums[i])<=2)
                j++;
            res += (j-i);
        };
        return res;
    }
};