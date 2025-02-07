// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {//path[i] = 'N', 'S', 'E' or 'W'
        int x=0, y = 0;
        unordered_set<string> s;
        s.insert(to_string(x)+"_" + to_string(y));
        for(char c: path) {
            switch(c) {
                case 'N':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
                default:
                    break;
            }
            if(s.find(to_string(x)+"_" + to_string(y))!=s.end())
                return true;
            s.insert(to_string(x)+"_" + to_string(y));
        }
        return false;
        
    }
};