// https://leetcode.com/problems/search-insert-position

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
	  int l = 0;
	  int h = nums.size();
	  while (l<h) {
		int m = l+(h-l)/2;
		if (nums[m] == target)
			return m;
		else if(nums[m] > target){
			h=m;
	    } else {
			l=m+1;
		}
	  };
	  
      return l;	 
  };
};