// https://leetcode.com/problems/maximum-number-of-k-divisible-components

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //edges[i] = [ai, bi]
        vector<vector<int>> adjList(n);
        for(auto edge: edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            adjList[n1].push_back(n2);
            adjList[n2].push_back(n1);
        };
        int count = 0;
        dfs(0, -1, adjList, values, k, count);
        return count;
    }
    int dfs(int curNode, int parent, vector<vector<int>>& adjList, vector<int>& values, int k, int& count) {
        int sum = 0; //sum of the subtree.
        for(auto neighbor: adjList[curNode]) {
            if(neighbor==parent)
                continue;
            sum += dfs(neighbor, curNode, adjList, values, k, count);
            sum %= k;
        }
        sum += values[curNode];
        sum%=k;
        if(sum==0) //if the sum of a subtree is 0.
            count++;
        return sum;
    }
};