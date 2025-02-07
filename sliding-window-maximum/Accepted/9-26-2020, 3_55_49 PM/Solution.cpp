// https://leetcode.com/problems/sliding-window-maximum

//BST Monotonic queue
class Solution {
public:
  //Brute force: TLE
/*  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		for(int i=k-1; i<nums.size(); i++) {
			ans.push_back(*max_element(nums.begin()+i-k+1, nums.begin()+i+1));
		}
		return ans;
  }*/
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	multiset<int> window;
	for(int i=0; i<nums.size(); i++) {
		window.insert(nums[i]);
		if(i-k+1>=0) {
			ans.push_back(*window.rbegin());
			window.erase(window.equal_range(nums[i-k+1]).first);
			//window.erase(nums[i-k+1]);
		}
	}
	return ans;
  }
};