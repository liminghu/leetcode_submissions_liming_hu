// https://leetcode.com/problems/remove-element

class Solution {
public:
   int removeElement(vector<int>& nums, int val) {
      int startIndex =0;
	  int endIndex = nums.size()-1;
	 // if (nums.size() == 0)
	 //	  return 0;
	  for(int i=0; i<nums.size(); ++i) {
		  while (nums[endIndex] == val) {
			--endIndex;
			if (endIndex == -1)
				return 0;
		  }
		if(i < endIndex) { 
			startIndex = i;
			if(nums[startIndex]==val) {
				//swap
				int temp=nums[endIndex];
				nums[endIndex] = nums[startIndex];
				nums[startIndex] = temp;
				while (nums[endIndex] == val) 
					--endIndex;
			}
		}
	  }
	  return endIndex + 1;
    }
};