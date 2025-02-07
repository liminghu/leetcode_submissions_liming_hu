// https://leetcode.com/problems/flatten-2d-vector

class Vector2D {
private:
    queue<int> q;
public:
    Vector2D(vector<vector<int>>& vec) {
        for(int i=0; i<vec.size(); i++) {
            for(int j=0; j<vec[i].size(); j++) {
                q.push(vec[i][j]);
            }
        }
    }
    
    int next() {
        int f = q.front();
        q.pop();
        return f;
        
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */