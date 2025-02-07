// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        //where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
        if(ops.size()==0)
            return m*n;
        int row = INT_MAX;
        int col = INT_MAX;
        for(auto& op: ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row*col;
    }
};