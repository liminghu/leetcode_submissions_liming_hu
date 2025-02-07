// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        int sz = nums.size();
        
        for(int i=0; i<sz; i++) {
            if(nums[i]%3 !=0)
                ans++;
        }
        return ans;
        
    }
};