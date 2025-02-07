// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii

class Solution {
public:
    //vector<int> ans;
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        //minimum number of operations required to make all elements in nums equal to 1
        //any index i from the array and flip all the elements from index i to the end of the array.
        //ans.resize(sz);
        return helper(nums, 0);
   
        
    }
    
    int helper(vector<int>& nums, int start) {
        int sz = nums.size();
        if(start == sz-1) {
            if(nums[start]==1)
                return 0;
            else
                return 1;
        }
        
        if(nums[start] == 1)
            return helper(nums, start+1);
        else {                
                for(int j=start+1; j<sz; j++) {
                    nums[j] = 1- nums[j];
                }                
                return  1+helper(nums, start+1);
        }        
        
        
    }
};