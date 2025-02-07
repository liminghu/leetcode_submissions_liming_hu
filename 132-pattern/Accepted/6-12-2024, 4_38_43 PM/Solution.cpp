// https://leetcode.com/problems/132-pattern

class Solution {
public:
/*
    Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].   
    Return true if there is a 132 pattern in nums, otherwise, return false.
*/
    bool find132pattern(vector<int>& nums) {
        if(nums.size() <3) 
            return false;
        
        stack<int> stk;
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            min_array[i] = min(min_array[i-1], nums[i]);
        }

        for(int j=nums.size()-1; j>0; j--) {
            if(nums[j]<=min_array[j])
                continue;
            while(!stk.empty() && stk.top() <=min_array[j]) {
                stk.pop();
            }

            if(!stk.empty() && stk.top() < nums[j]) {
                return true;
            }
            stk.push(nums[j]);
        }

        return false;
        
    }
};