// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> output;
    int n, k;
    void backtrack(int first, vector<int> cur, vector<int>& nums) {
        if(cur.size() == k)
            output.push_back(cur);
        for(int i=first; i<n; i++) {
            cur.push_back(nums[i]);
            backtrack(i+1, cur, nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) { //distinct.
        n = nums.size();
        for(k=0; k<n+1; k++) {
            vector<int> cur;
            backtrack(0, cur, nums);
        }
        return output;
    }

};