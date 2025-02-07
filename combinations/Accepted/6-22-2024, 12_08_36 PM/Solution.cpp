// https://leetcode.com/problems/combinations

class Solution {
public:
/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/
    int k;
    int n;

    vector<vector<int>> combine(int n, int k) {//1 <= n <= 20; 1 <= k <= n
        this->k = k;
        this->n = n;
        vector<vector<int>> ans;
        vector<int> path = {};
        backtrack(path, 1, ans); //first element: 1
        return ans;
    }

    void backtrack(vector<int>& path, int startNum, vector<vector<int>>& ans) {
       if(path.size() == k) {
            ans.push_back(path);
            return;
       } 

       for(int num=startNum; num<=n; num++) {
            path.push_back(num);
            backtrack(path, num+1, ans);
            path.pop_back();
       }
       return;

    }
};