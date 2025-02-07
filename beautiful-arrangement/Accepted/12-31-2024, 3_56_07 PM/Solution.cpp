// https://leetcode.com/problems/beautiful-arrangement

class Solution {
    int res = 0;
public:
    int countArrangement(int n) {//1 <= n <= 15
        vector<bool> visited(n+1, false);
        helper(n, 1, visited);
        return res;
    }
    void helper(int n, int cur, vector<bool>& visited) {
        if(cur>n) {
            res++;
            return;
        }
        for(int i=1; i<=n; i++) {
            if(visited[i])
                continue;
            if(i%cur==0 || cur%i==0) {
                visited[i] = true;
                helper(n, cur+1, visited);
                visited[i] = false;
            }
        }
    }
};