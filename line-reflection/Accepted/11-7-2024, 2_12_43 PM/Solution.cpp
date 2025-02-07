// https://leetcode.com/problems/line-reflection

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int n = points.size();
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        unordered_set<string> s;
        for(auto p: points) {
            min_x = min(min_x, p[0]);
            max_x = max(max_x, p[0]);
            string key = to_string(p[0]) + "_" + to_string(p[1]);
            s.insert(key);
        };
        float mid = (max_x+min_x)/2.0;
        for(auto p: points) {
            if(p[0] > mid ) 
                p[0] = p[0] - 2 *( p[0] - mid );
            else 
                p[0] = p[0] + 2 *( mid - p[0] );
            string key = to_string(p[0]) + "_" + to_string(p[1]);    
            if(s.find(key) == s.end())
                return false;
        }
        return true;
    }
};