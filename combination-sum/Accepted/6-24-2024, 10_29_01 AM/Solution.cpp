// https://leetcode.com/problems/combination-sum

class Solution {
public:
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of 
candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if 
the frequency of at least one of the chosen numbers is different.
 */
    vector<vector<int>> ans = {};
    vector<int> path = {};
    int pathSum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { //1 <= candidates.length <= 30; 2 <= candidates[i] <= 40
                                                                              //All elements of candidates are distinct.; 1 <= target <= 40
        int start = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, start);
        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int start) {

        if(pathSum == target) {
            ans.push_back(path);
            return;
        };
        if(start >=candidates.size() || pathSum > target) {
            return;
        };
        for(int i=start; i<candidates.size() && pathSum+candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            pathSum += candidates[i];
            backtrack(candidates, target, i); //we did not add 1 to start, so it means the current num can be used unlimited times.
            pathSum -= path.back();
            path.pop_back();
        }
    };
};