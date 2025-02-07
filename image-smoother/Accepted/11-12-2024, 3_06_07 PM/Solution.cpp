// https://leetcode.com/problems/image-smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<pair<int,int>>> conv = { { {-1, -1}, {-1, 0}, {-1, 1} },
                                               { { 0, -1}, { 0, 0}, { 0, 1} },
                                               { { 1, -1}, { 1, 0}, { 1, 1} } };
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));
        for(int i=0; i<img.size(); i++) {
            for(int j=0; j<img[0].size(); j++) {
                int sum = 0;
                int count = 0;
                for(int k=0; k<3; k++) {
                    for(int l=0; l<3; l++) {
                        if(i+conv[k][l].first >=0 &&  i+conv[k][l].first <img.size() && j+conv[k][l].second >=0 &&  j+conv[k][l].second <img[0].size()) {
                            sum += img[i+conv[k][l].first][j+conv[k][l].second];
                            count++; 
                        }
                    }
                }
                res[i][j] = floor(sum/count);  
            }
        }
        return res;
    }
};