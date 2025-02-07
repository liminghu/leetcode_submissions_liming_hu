// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size()<=2) return nums.size();
		int count = 2;
		for(int i=2; i<nums.size();++i) {
			if (nums[i] != nums[count-2]) {
				count++;
				nums[count-1] = nums[i];
				
			}
		}
		return count;  
    }
};