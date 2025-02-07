// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int temp;
      for(int i=0; i<nums.size()/2; ++i) {
	    swap(&nums[i], &nums[nums.size()-1-i]);
	  }	;
	  for(int i=0; i<k/2; ++i) {
		swap(&nums[i], &nums[k-1-i]);
	  }
	  for(int i=k; i<(k+nums.size())/2; ++i) {
		swap(&nums[i], &nums[nums.size()-1-i+k]);
	  }
    }
	void swap(int *a, int *b) {
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
};