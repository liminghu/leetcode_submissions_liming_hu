// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {//1 <= m, n <= 200
        int m = picture.size();
        int n = picture[0].size();
        unordered_map<int, set<int>> rows;
        unordered_map<int, set<int>> cols;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(picture[i][j] == 'B') {
                    rows[i].insert(j);
                    cols[j].insert(i);
                }
            }
        }
        int ret = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n && rows.count(i); j++) {
                if(picture[i][j] == 'B' && rows[i].size()==target && cols[j].size()==target ) {
                    bool lonely = true;
                    for(int r:cols[j]) { //for rows which have B pixel.
                        if(rows[r]!=rows[i]) {
                            lonely = false;
                            break;
                        }
                    }
                    ret += lonely;
                }
            }
        }
        return ret;        
    }
};