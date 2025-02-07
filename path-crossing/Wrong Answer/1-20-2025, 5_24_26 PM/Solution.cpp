// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {//path[i] = 'N', 'S', 'E' or 'W'
        int x=0, y = 0;
        int n = path.length();
        for(char c: path) {
            switch(c) {
                case 'N':
                    x--;
                    break;
                case 'E':
                    y++;
                    break;
                case 'S':
                    x++;
                    break;
                case 'W':
                    y--;
                    break;
                default:
                    break;
            }
            if(x==0 && y == 0)
                return true;
        }
        return false;
        
    }
};