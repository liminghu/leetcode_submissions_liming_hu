// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq; //min
        vector<vector<int>> time(rows, vector<int>(cols, INT_MAX));
        pq.push({0, 0, 0}); //time, x, y
        time[0][0] = 0;

        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()) {
            auto [curTime, x, y] = pq.top();
            pq.pop();
            if(x == rows-1 && y == cols-1)
                return curTime;
            for(auto [dx, dy]: dirs) {
                int newX = x + dx;
                int newY = y + dy;
                if(newX>=0 && newX<rows && newY>=0 && newY < cols) {
                    int waitTime = max(moveTime[newX][newY]-curTime, 0);
                    int newTime = curTime + 1 + waitTime;
                    if(newTime < time[newX][newY]) {
                        time[newX][newY] = newTime;
                        pq.push({newTime, newX, newY});
                    };
                }
            }
        }
        return -1; //unreachable.
    }
};