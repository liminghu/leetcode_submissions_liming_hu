// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0.0;
        for(auto& p1:p) {
            for(auto& p2:p) { 
                for(auto& p3:p) {
                    double area1 = 0.5*(p2[0]-p1[0])*(p3[1]-p2[1]);   //1,2
                    double area2 = 0.5*(p3[0]-p2[0])*(p1[1]-p3[1]);  //1,3
                    double area3 = 0.5*(p3[0]-p2[0])*(p3[1]-p2[1]);   //2,3
                    res = max(res, area1+area2+area3);
                }
            }
        }
        return res;
    }
};