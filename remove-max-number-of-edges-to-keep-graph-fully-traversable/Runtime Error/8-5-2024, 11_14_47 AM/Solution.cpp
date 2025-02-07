// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

/*Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei 
between nodes ui and vi, find the maximum number of edges you can remove so that after removing the 
edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed 
by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
*/
class Solution {
public:
    int father[10001];
    int father0[10001];
    int findFather(int i) {
        if(father[i] != i) 
            father [i]= findFather(father[i]);
        return father[i];        
    }

    void unionSet(int i, int j) { //merge j to i.
        i = father[i];
        j = father[j];
        if( i < j )
            father[j] = i;
        else
            father[i] = j;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /*
            1 <= n <= 105
            1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
            edges[i].length == 3
            1 <= typei <= 3
            1 <= ui < vi <= n
            All tuples (typei, ui, vi) are distinct.
        */

        //[typei, ui, vi]
        int sz = edges.size();
        //Type 1: Can be traversed by Alice only.
        //Type 2: Can be traversed by Bob only.
        //Type 3: Can be traversed by both Alice and Bob.
        vector<vector<int>> edges1;
        vector<vector<int>> edges2;
        vector<vector<int>> edges3;
        for(auto edge: edges) {
            if(edge[0] == 1)
                edges1.push_back({edge[1], edge[2]});
            else if(edge[0] == 2) 
                edges2.push_back({edge[1], edge[2]});
            else
                edges3.push_back({edge[1], edge[2]});
        }

        for(int i=0; i<n; i++) { //initialize union set.
            father[i] = i;
        };

        int count3=0;
        int count2=0;
        int count1=0;
        for(auto edge: edges3) {
            int a = edge[0];
            int b = edge[1];
            if( findFather(a) == findFather(b) )
                continue;
            else {
                unionSet(a,b);
                count3++;
            }
        };
        memcpy(father0, father, sizeof(father)); //dest source
        for(auto edge: edges2) {
            int a = edge[0];
            int b = edge[1];
            if( findFather(a) == findFather(b) )
                continue;
            else {
                unionSet(a,b);
                count2++;
            }
        };
        if(count3+count2 != n-1)
            return -1;

        memcpy(father, father0, sizeof(father));
        for(auto edge: edges1) {
            int a = edge[0];
            int b = edge[1];
            if( findFather(a) == findFather(b) )
                continue;
            else {
                unionSet(a,b);
                count1++;
            }
        };
        if(count3+count1 != n-1)
            return -1;


        return edges.size()-count3-count2-count1;
        
    }
};