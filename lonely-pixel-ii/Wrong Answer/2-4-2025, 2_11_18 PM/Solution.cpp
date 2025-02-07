// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size();
        int n = picture[0].size();
        //Row r and column c both contain exactly target black pixels.
        unordered_set<int> rowB;
        for(int i=0; i<m; i++) {
            int rCount = 0;
            for(int j=0; j<n; j++) {
                if(picture[i][j]=='B')
                    rCount++;
            };
            if(rCount==target)
                rowB.insert(i);
        }
        unordered_set<int> colB;
        for(int j=0; j<n; j++) {
            int cCount = 0;
            for(int i=0; i<m; i++) {
                if(picture[i][j]=='B')
                    cCount++;
            };
            if(cCount==target)
                colB.insert(j);
        };
        int ret = 0;
        for(int i=0; i<m; i++) {
            if (rowB.find(i) != rowB.end()) {
                for(int j=0; j<n; j++) {
                    if(picture[i][j]=='B' && colB.find(j) != colB.end()) {
                        ret++;
                    }
                };
            }
        }   
        return ret;             
    }
};