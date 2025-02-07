// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

//an array nums of distinct integers, return all the possible permutations
    vector<vector<int>> permute(vector<int>& nums) { //1 <= nums.length <= 6; -10 <= nums[i] <= 10; All the integers of nums are unique.
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums) {
        if(path.size()== nums.size()) {
            res.push_back(path);
            return;
        };

        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
  
    };
};