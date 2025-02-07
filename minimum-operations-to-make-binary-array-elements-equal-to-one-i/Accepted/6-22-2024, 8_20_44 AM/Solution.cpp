// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i

class Solution {
public:

    int minOperations(vector<int>& nums) {
        int ans = 0; 
        int sz = nums.size();
        if(sz <3)
            return -1;
        
        for(int i=0; i<sz; i++) {
            if(i == nums.size()-3) {
                if(nums[i] + nums[i+1] + nums[i+2]==0) {
                    ans++;
                }else if(nums[i] + nums[i+1] + nums[i+2]<3) {
                    ans = -1;
                }
                break;
            }
        
            if(nums[i] == 0) {
                nums[i] = 1;
                nums[i+1] = 1-nums[i+1];
                nums[i+2] = 1-nums[i+2];
                ans++;               
            }            
        }
        return ans;     
    }
    
};