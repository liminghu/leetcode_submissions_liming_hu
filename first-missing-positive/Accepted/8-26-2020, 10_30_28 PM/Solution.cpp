// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      if (nums.size() == 0) 
          return 1;
      int n= nums.size();
      int containsOne =0; 
      
      //step 1
      for (int i=0; i<n; i++) {
        if (nums[i] == 1) {
            containsOne = 1;
        } else if ((nums[i] <= 0) || (nums[i] > n)) {
          nums[i] = 1;
        }
      }
      
      if (containsOne == 0) return 1;
      
      //step 2
      for(int i=0; i<n; i++) {
        int index = abs(nums[i])-1;
        if(nums[index]>0) nums[index] = -1 * nums[index];
      }
      
      //step 3
      for (int i=0; i<n; i++) {
        if(nums[i] >0) {
            return i+1;
        }
      }
      
      //[1 2 3] -> 4
      return n+1;
    }
};