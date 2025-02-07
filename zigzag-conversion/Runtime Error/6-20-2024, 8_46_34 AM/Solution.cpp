// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
 
        int sz = s.length();
        string ans;
        if(numRows == 1)
            return s;

        vector<vector<char>> ans_m(numRows, vector<char>(sz/(2*numRows-2)*2+2, ' '));

        int col = 0;
        int index = 0;
        while(index <sz) {
            //vertical
            for(int j=0; j<numRows; j++) {
                if(index >=sz )
                    break;
                ans_m[j][col] = s[index];
                index++;
            }
            col++;
            //diagonal up
            for(int j=numRows-2; j>=1; j--) {
                if(index >=sz )
                    break;
                ans_m[j][col] = s[index];
                index++;
                col++;
            };
        }

        for(int i=0; i<ans_m.size(); i++) {
            for(int j=0; j<ans_m[0].size(); j++) {
                if(ans_m[i][j]!= ' ') 
                    ans.push_back(ans_m[i][j]);
            }
        }

        return ans;

    }
};