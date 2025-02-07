// https://leetcode.com/problems/transformed-array

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++) {
            if(nums[i]==0)
                res[i] = nums[i];
            else if(nums[i]>0) {
                int steps = nums[i]%n;
                int idx = (i+steps)%n;
                res[i] = nums[idx];
            } else if(nums[i]<0) {
                int steps = abs(nums[i])%n;
                int idx = (i-steps+n)%n;
                res[i] = nums[idx];  
            }
        };
        return res;
    }
};