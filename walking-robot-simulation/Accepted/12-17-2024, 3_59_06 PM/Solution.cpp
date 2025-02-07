// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        /*  -2: Turn left 90 degrees.
            -1: Turn right 90 degrees.
            1 <= k <= 9: Move forward k units, one unit at a time.
        */
        // grid point obstacles[i] = (xi, yi)
        /*  North means +Y direction.
            East means +X direction.
            South means -Y direction.
            West means -X direction.
        */
        //   W
        //S -|- N
        //   E
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //N(0), E(1), S(2), W(3)
        unordered_set<string> objs;
        for(auto obj:obstacles) {
            objs.insert(to_string(obj[0]) + "_" + to_string(obj[1]));
        } 
        int dir = 0; //N
        int x = 0;
        int y = 0;
        int maxDistance = 0;
        for(int i=0; i<commands.size(); i++) {
            if(commands[i] == -2) //turn left
                dir = (dir+3)%4;
            else if(commands[i] == -1) //turn right.
                dir = (dir+1)%4;
            else {
                int step = 0;
                while( step<commands[i] && objs.find(to_string(x+dirs[dir][0])+"_"+to_string(y+dirs[dir][1]))==objs.end() ) {
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                    step++;
                }
            }
            maxDistance = max(maxDistance, x*x+y*y);
        }
        return maxDistance;
    }
};