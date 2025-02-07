// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> combinationSum3(int k, int n) { //2 <= k <= 9; 1 <= n <= 60

        int start = 1;
        used = vector<bool>(10, false);
        backtrack(k, n, start, used);

        return ans;
        
    }

    void backtrack(int k, int n, int start, vector<bool> used) {
        if(path.size() == k) {
            int sum = 0;
            for(int i=0; i<k; i++) {
                sum+=path[i];
            }
            if(sum==n)
                ans.push_back(path);            
            return;
        };

        for(int i=start; i<=9; i++) {
            if(used[i] == false) {
                used[i] = true;
                path.push_back(i);
                backtrack(k, n, i+1, used);
                path.pop_back();
                used[i] = false;

            }

        }

    };
};