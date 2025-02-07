// https://leetcode.com/problems/search-insert-position

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
	  int l = 0;
	  int h = nums.size()-1;
	  while (l<h) {
		int m = (l+h)/2;
		if (nums[m] == target)
			return m;
		else if(nums[m] > target){
			h=m-1;
	    } else {
			l=m+1;
		}
	  };
	  
	  if (l==h) 
		return l+1;
	  else if(h<l)
        return l;
      else
        return h;		 
  };
};