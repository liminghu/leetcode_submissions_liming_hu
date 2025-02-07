// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) { //For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i
        vector<vector<int>> top_dim;
        float max_diag = 0;
        vector<int> vl;
        for(int i=0; i<dimensions.size(); i++) {
            float diag_i = sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if(diag_i > max_diag) { 
                max_diag = diag_i;
                vl.clear();
                vl.push_back(i);
            } else if(diag_i == max_diag)
                vl.push_back(i);
        };
        int max_area = 0;
        for(int i=0; i<vl.size(); i++) {
            int area_i = dimensions[vl[i]][0]*dimensions[vl[i]][1];
            if(area_i > max_area) 
                max_area = area_i;
        };
        return max_area;
    }
};