// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		//Solution: DFS
		//Time complexity: O(n!)
		//Space complexity: O(n)
		
		used = vector<int>(nums.size());

		dfs(nums, 0);
		return ans;
    }
private:
    vector<int> used;	 
    vector<int> path;
    vector<vector<int>> ans;
	void dfs(const vector<int>& nums, int d) {
		const int n = nums.size();
		if( d == n) {
			ans.push_back(path);
			return;
		};
		
		for(int i=0; i < n; i++) {
			if(used[i]) continue;
            used[i] = 1;
			path.push_back(nums[i]);
			dfs(nums, d+1);
			path.pop_back();
			used[i] = 0;
		}
	}
};