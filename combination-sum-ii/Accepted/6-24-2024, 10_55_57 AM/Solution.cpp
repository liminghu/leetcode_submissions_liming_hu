// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/
    vector<vector<int>> ans = {};
    vector<int> path ={};
    int pathSum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { //1 <= candidates.length <= 100; 1 <= candidates[i] <= 50; 1 <= target <= 30

        int start = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, start);
        return ans;        
    }

    void backtrack(vector<int>&  candidates, int target, int start) {
        
        if(pathSum == target) {
            ans.push_back(path);
        }
        if(start>=candidates.size() || pathSum >= target) {
            return;
        };

        for(int i=start; i<candidates.size() && pathSum+candidates[i] <= target; i++) {
            //same level, if we used the element before, just skip.
            if(i>start && candidates[i] == candidates[i-1]) {
                continue;
            }
            pathSum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, i+1);
            pathSum -= path.back();
            path.pop_back();            
        }
    };
};