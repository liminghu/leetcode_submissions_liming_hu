// https://leetcode.com/problems/3sum-smaller

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        //edge cases
        if(n<3)
            return ans;
        
        int sum_i_j =0;
        for(int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                sum_i_j = nums[i]+nums[j];
                for(int k=j+1; k<n; k++) {
                    if(sum_i_j+nums[k]<target)
                       ans++;
                }
            }
        }

        return ans;

        
    }
};