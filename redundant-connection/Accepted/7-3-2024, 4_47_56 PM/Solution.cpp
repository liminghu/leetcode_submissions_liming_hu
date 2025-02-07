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
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);        
        parents_ = vector<int>(n + 1, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu])
            parents_[pu] = pv;           
        else if (ranks_[pu] > ranks_[pv])
            parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};
 
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
        UnionFindSet s(edges.size());
        
        for(const auto& edge: edges)
            if (!s.Union(edge[0], edge[1]))
                return edge;
        
        return {};
    }
};