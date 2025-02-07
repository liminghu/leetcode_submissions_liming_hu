// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        // '#'(stone), '*'(obstacles), '.'(empty)
        vector<vector<char>> rotated(n, vector<char>(m, '.'));
        for(int i=0; i<m; i++) { //new column.
            int lowestRowWithEmptyCell = n-1; 
            for(int j=n-1; j>=0; j--) { //new rows.
                //roated[j][i]    //boxGrid[i][j]
                //Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box.
                if(boxGrid[i][j] == '#') {
                    rotated[lowestRowWithEmptyCell][m-i-1] = '#';
                    lowestRowWithEmptyCell--;
                }
                if(boxGrid[i][j]== '*') {
                   rotated[j][m-i-1] = '*';
                   lowestRowWithEmptyCell = j-1; 
                }
            }
        }
        return rotated;
    }
};