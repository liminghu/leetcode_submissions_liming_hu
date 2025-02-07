// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
      int startIndex =0;
	  int endIndex = nums.size()-1;
	  int len = nums.size();
	  int i = 0;
	  while (i<nums.size()) {
		while ((endIndex < len) && (nums[endIndex] == nums[endIndex-1]))
		  --endIndex;
		if (i < endIndex) {
			startIndex = i;
			if ((startIndex + 1 < len) && (nums[startIndex] == nums[startIndex + 1])) {
				//swap
				int temp = nums[endIndex];
				nums[endIndex] = nums[startIndex];
				nums[startIndex] = temp;
				endIndex--;
				while ((endIndex < len) && (nums[endIndex] == nums[endIndex - 1]))
					--endIndex;
			}
			i++;
		}
		else
			break;
	  }
	  return endIndex + 1;
    }
};