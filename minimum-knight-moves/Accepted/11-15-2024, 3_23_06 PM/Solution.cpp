// https://leetcode.com/problems/minimum-knight-moves

class Solution {
    vector<pair<int, int>> dirs = { {1,2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
public:
    int minKnightMoves(int x, int y) {
        //Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
        x = abs(x);
        y = abs(y);
        queue<pair<int,int>> q;
        q.push({0, 0});
        unordered_set<string> visited;
        int res = 0;
        while(!q.empty()) {    //BFS
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                pair<int, int> f = q.front();
                q.pop();
                int curX = f.first;
                int curY = f.second;
                if(curX==x && curY == y)
                    return res;
                for(auto dir:dirs) {
                    int newX = curX + dir.first;
                    int newY = curY + dir.second;
                    string key = to_string(newX) + "_"+to_string(newY); 
                    if(visited.find(key) == visited.end() && newX >=-1 && newY >=-1) {
                        visited.insert(key);
                        q.push({newX, newY});
                    };
                }
            }
            res++;
        }
        return -1;

    }
};