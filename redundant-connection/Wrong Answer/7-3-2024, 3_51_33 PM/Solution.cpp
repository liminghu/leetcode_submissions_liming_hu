// https://leetcode.com/problems/redundant-connection

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one 
additional edge added. The added edge has two different vertices chosen from 1 to n, and
 was not an edge that already existed. The graph is represented as an array edges of length 
 n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) { //n == edges.length
                                                                    //n == edges.length
                                                                    //3 <= n <= 1000
                                                                    //edges[i].length == 2
                                                                    //1 <= ai < bi <= edges.length
                                                                    //ai != bi
                                                                    //There are no repeated edges.
                                                                    //The given graph is connected.      
        //find the loop and remove the last edge in the loop.
        int sz = edges.size();
        vector<int> ans;

        unordered_set<int> s;
        for(int i=0; i<sz; i++) {
            int node_a = edges[i][0];
            int node_b = edges[i][1];
            if( s.find(node_a) != s.end() && s.find(node_b) != s.end() ) {
                ans.push_back(node_a);
                ans.push_back(node_b);
            } else {
                s.insert(node_a);
                s.insert(node_b);
            }
        }  

        vector<int> result;
        if(ans.size()>=2) {
            int node_b = ans.back();
            ans.pop_back();
            int node_a = ans.back();

            result.push_back(node_a);
            result.push_back(node_b);
        }
        return result;
    }
};