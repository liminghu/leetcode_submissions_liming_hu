// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees

/*
There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. 
You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where 
edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and 
edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.
*/
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
                                                        /*
                                                        1 <= n, m <= 105
                                                        edges1.length == n - 1
                                                        edges2.length == m - 1
                                                        edges1[i].length == edges2[i].length == 2
                                                        edges1[i] = [ai, bi]
                                                        0 <= ai, bi < n
                                                        edges2[i] = [ui, vi]
                                                        0 <= ui, vi < m
                                                        The input is generated such that edges1 and edges2 represent valid trees.
                                                        */
        int d1 = getDiameter(edges1);
        int d2 = getDiameter(edges2);
        return max(max(d1 - 1, d2 - 1), d1 / 2 + d2 / 2 + 1);
    }

private:
    int getDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> map;
        for (auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            map[i].push_back(j);
            map[j].push_back(i);
        }

        int res = 0;
        dfs(0, -1, map, res);  //0: current node, -1: parent. 

        return res;
    }

    int dfs(int node, int parent, unordered_map<int, vector<int>>& map, int& res) {
        int maxDepth = 1; ///current max depth.
        for (int neighbor : map[node]) {
            if (neighbor == parent)
                continue;
            int depth = dfs(neighbor, node, map, res);
            res = max(res, depth + maxDepth);
            maxDepth = max(maxDepth, 1 + depth);
        }
        return maxDepth;
    }
};