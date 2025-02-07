// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { //distinct.
        //DFS+backtracking.
		vector<vector<int>> ans;
		vector<int> cur;
		for(int i = 0; i <= nums.size(); i++)
			dfs(nums, i, 0, cur, ans);    //i:size.    0: start.
		return ans;
    }
private: 
    //n: subset length.
	//s: starting element.
	void dfs(const vector<int>& nums, int n, int s, vector<int>& cur, vector<vector<int>>& ans) {
		if(cur.size() == n) {
			ans.push_back(cur); //push back will make a copy.
			return;
		};
		
		for(int i = s; i < nums.size(); i++) {
			cur.push_back(nums[i]);
			dfs(nums, n, i + 1, cur, ans);
			cur.pop_back();   //backtracking.
		}
	}
};