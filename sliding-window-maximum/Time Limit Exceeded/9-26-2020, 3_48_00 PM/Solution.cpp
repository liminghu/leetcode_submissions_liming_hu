// https://leetcode.com/problems/sliding-window-maximum

//BST Monotonic queue
class Solution {
public:
  //Brute force.
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		for(int i=k-1; i<nums.size(); i++) {
			ans.push_back(*max_element(nums.begin()+i-k+1, nums.begin()+i+1));
		}
		return ans;
  }
};