// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { //distinct.
        vector<vector<int>> ans;
        vector<int> path = {};
        backtrack(nums, 0, path, ans); //first element: 0
        return ans;
    }

      void backtrack(vector<int>& nums, int startNum, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        if(startNum >=nums.size()) {
            return;
        } 

       for(int num=startNum; num<nums.size(); num++) {
            path.push_back(nums[num]);
            backtrack(nums, num+1, path, ans);
            path.pop_back();
       }
       return;

    }

};