// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0.0;
        for(auto& p1:p) {
            int x1 = p1[0];
            int y1 = p1[1];
            for(auto& p2:p) {
                int x2 = p2[0];
                int y2 = p2[1]; 
                for(auto& p3:p) {
                    int x3 = p3[0];
                    int y3 = p3[1];                    
                    double area = 0.5 *abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};