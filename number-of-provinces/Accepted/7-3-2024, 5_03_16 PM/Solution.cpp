// https://leetcode.com/problems/number-of-provinces

class UnionFindSet {
public:
    UnionFindSet(int n) {
        parents_ = vector<int>(n + 1, 0);
        ranks_ = vector<int>(n + 1, 0);
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        if (ranks_[pu] > ranks_[pv]) {
            parents_[pv] = pu;
        } else if (ranks_[pv] > ranks_[pu]) {
            parents_[pu] = pv;
        } else {
            parents_[pu] = pv;
            ++ranks_[pv];
        }
 
        return true;
    }
    
    int Find(int id) {        
        if (id != parents_[id])
            parents_[id] = Find(parents_[id]);        
        return parents_[id];
    }
    
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
        UnionFindSet s(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j] == 1) s.Union(i, j);
        
        unordered_set<int> circles;
        for (int i = 0; i < n; ++i)
            circles.insert(s.Find(i));
        
        return circles.size();        
    }
};