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
        vector<int> cur = {};
        backtrack(cur, 1, ans); //first element: 1
        return ans;
    }

    void backtrack(vector<int>& cur, int startNum, vector<vector<int>>& ans) {
       if(cur.size() == k) {
            ans.push_back(cur);
            return;
       } 

       for(int num=startNum; num<=n; num++) {
            cur.push_back(num);
            backtrack(cur, num+1, ans);
            cur.pop_back();
       }
       return;

    }
};