// https://leetcode.com/problems/factor-combinations

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> rets;
        vector<int> temp;
        helper(rets, temp, n, 2);  //result, temp result, n, start
        return rets;
    }
    void helper(vector<vector<int>>& rets, vector<int>& temp, int n, int start) {
        if( n == 1 ) {
            if(temp.size() > 1 )  { //12, not valid.
                rets.push_back(temp);
                return;
            }
        }

        for(int i=start; i<=n; i++) {
            if( n % i == 0 ) {
                temp.push_back(i);
                helper(rets, temp, n/i, i); //start from i to prevent duplicates.
                temp.pop_back();   //backtracking...
            }
        }
    }

};