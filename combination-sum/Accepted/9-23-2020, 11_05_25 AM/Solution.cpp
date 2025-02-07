// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { //All numbers (including target) will be positive integers.
		vector<vector<int>> ans;
		vector<int> cur;
		std:sort(candidates.begin(), candidates.end()); //increasing.
		dfs(candidates, target, 0, cur, ans); //0: start
		return ans;
    }
private:
    //s: start.
	void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
		if(target == 0) {
		ans.push_back(cur);
		return;
		}
		
		for(int i = s; i < candidates.size(); i++) {
			if(candidates[i] > target) break; //branch pruning, based on sorting.
			cur.push_back(candidates[i]);
			dfs(candidates, target-candidates[i], i, cur, ans);
			cur.pop_back();   //backtracking.
		}
	}
};