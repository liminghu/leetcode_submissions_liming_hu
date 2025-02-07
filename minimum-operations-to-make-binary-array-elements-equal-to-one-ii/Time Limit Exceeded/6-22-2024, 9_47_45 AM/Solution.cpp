// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii

class Solution {
public:
    //vector<int> ans;
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        //minimum number of operations required to make all elements in nums equal to 1
        //any index i from the array and flip all the elements from index i to the end of the array.
        //ans.resize(sz);
        //return helper(nums, 0);
        int ans = 0;
        for(int i=0; i<sz; i++) {
            if(nums[i] == 1 )
                continue;
            else {  
                ans++;              
                for(int j=i+1; j<sz; j++) {
                    nums[j] = 1- nums[j];
                }
            }     
        }  
        return ans;   
    }
};