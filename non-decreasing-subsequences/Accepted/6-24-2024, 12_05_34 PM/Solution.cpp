// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
public:
/*
Given an integer array nums, return all the different possible non-decreasing subsequences 
of the given array with at least two elements. 
You may return the answer in any order.
*/
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        int start = 0;
        backtrack(nums, start);

        return ans;        
    }

    void backtrack(vector<int>& nums, int start) {
        unordered_map<int, int> dict; //record the current level: is the number used before? 

        if( path.size()>=2) {
            ans.push_back(path);
        };
        if(start == nums.size() ) {
            return;
        };

        for(int i=start; i<nums.size(); i++) {
            if(path.size() >0 && path.back() > nums[i])
                continue;
            if(dict.find(nums[i])!=dict.end())
                continue;
            path.push_back(nums[i]);
            dict[nums[i]] = i;
            backtrack(nums, i+1);
            path.pop_back();
        }

    }
};