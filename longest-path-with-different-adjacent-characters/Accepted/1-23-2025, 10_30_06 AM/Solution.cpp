// https://leetcode.com/problems/longest-path-with-different-adjacent-characters

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        //Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
        unordered_map<int, vector<int>> children; //parent node, children node.
        unordered_map<int, int> len; //node id, length.
        int maxPath = 1;
        int n = parent.size();
        for(int i=0; i<n; i++) {
            if(parent[i] != -1) {
                children[ parent[i] ].push_back(i);
            };
        };
        dfs(0, s, children, len, maxPath);
        return maxPath;
    }
    void dfs(int node, string& s, unordered_map<int, vector<int>>& children, unordered_map<int, int>& len, int& maxPath) {
        if(children[node].size()==0) {
            len[node] = 1;
            return;
        };
        int curPath = 1;
        vector<int> temp;
        for(int child: children[node]) {
            dfs(child, s, children, len, maxPath);
            if(s[child] != s[node]) {
                curPath = max(curPath, len[child]+1);
                temp.push_back(len[child]);
            };
        }
        len[node] = curPath;
        sort(temp.rbegin(), temp.rend()); //descreasing
        if(temp.size() >= 2) {
            maxPath = max(maxPath, temp[0]+temp[1]+1);
        } else if(temp.size()==1) {
            maxPath = max(maxPath, temp[0]+1);
        } //else
          //  maxPath = max(maxPath, 1);
    }
};