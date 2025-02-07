// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //edge cases;
        int n=nums.size();
        if(k>n)
            return 0;
        
        float Inf = numeric_limits<float>::infinity();
        double ans = -Inf;
        int start = 0;
        int end = k-1;
        double sum =0;
        for(int j=start; j<start+k; j++) {
            sum+= nums[j];        
        }

        if(k==n)
            return (double)sum/k;

        for(int i=k; i<n; i++) {
            sum = sum-nums[i-k]+nums[i];
            if(sum>ans) 
                ans = sum;
        }

        return ans/k;

        
    }
};