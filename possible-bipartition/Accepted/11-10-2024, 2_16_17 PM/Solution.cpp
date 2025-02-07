// https://leetcode.com/problems/possible-bipartition

/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, 
and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the 
person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].

Example 2:
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 
Constraints:
1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.
*/
class Solution {
vector<vector<int>> adj_;
vector<int> colors_;
public:
    //We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) { //dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi
        adj_ = vector<vector<int>>(n);
        for(auto d:dislikes) {
            adj_[ d[0] - 1 ].push_back(d[1] - 1);
            adj_[ d[1] - 1 ].push_back(d[0] - 1);
        }
        colors_ = vector<int>(n,0); //0:unknown; 1: red. -1:blue
        for(int i=0; i<n; i++) {
            if(colors_[i]==0 && !dfs(i, 1))
                return false;
        }
        return true;
    }
    bool dfs(int cur, int color) {
        colors_[cur] = color;
        for(int nxt: adj_[cur]) {
            if(colors_[nxt] == color) 
                return false;
            if(colors_[nxt] == 0 && !dfs(nxt, -color))
                return false;
        }
        return true;
    }
};