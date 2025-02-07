// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //edge cases;
        int n=nums.size();
        if(k>n)
            return 0;
        
        double cur_sum = 0;
        for(int j=0; j<k; j++) {
            cur_sum+= nums[j];        
        }
        double ans = cur_sum;

        if(k==n)
            return (double)cur_sum/k;

        for(int i=k; i<n; i++) {
            cur_sum = cur_sum-nums[i-k]+nums[i];
            if(cur_sum>ans) 
                ans = cur_sum;
        }

        return ans/k;

        
    }
};