// https://leetcode.com/problems/valid-word-square

class Solution {
    vector<vector<char>> square= vector(501, vector<char>(501, 0) );
public:
    bool validWordSquare(vector<string>& words) {
        //valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).
        int numRows = words.size();
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<words[i].size(); j++) {
                square[i][j] = (char)words[i][j];
            }
        };
        for(int i=0; i<numRows; i++) { //columns
            for(int j=0; j<words[i].size(); j++) {
                if( square[j][i] != square[i][j])
                    return false;
            }
        };
        return true;

    }
};