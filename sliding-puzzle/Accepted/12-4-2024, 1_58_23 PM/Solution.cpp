// https://leetcode.com/problems/sliding-puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        string goal;
        string start;
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                start += ( board[r][c] + '0' );
                goal  += ( (r*cols+c+1)%(rows*cols)+'0' ); //12345.......0
            }
        }
        if(start==goal)
            return 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<string> visited;
        visited.insert(start);
        int steps = 0;
        queue<string> q;
        q.push(start);
        while(!q.empty()) {
            steps++;
            int sz = q.size();
            while(sz-->0) {
                string s = q.front();
                q.pop();
                int p = s.find('0');
                int y = p / cols;
                int x = p % cols;
                for(auto dir: dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx<0 || ny<0 || nx>=cols || ny >= rows)
                        continue;
                    int pp = ny * cols + nx;
                    string t(s);
                    swap(t[p], t[pp]);
                    if(visited.count(t))
                        continue;
                    if(t==goal)
                        return steps;
                    visited.insert(t);
                    q.push(t);
                }
            }
        }
        return -1;
    }
};