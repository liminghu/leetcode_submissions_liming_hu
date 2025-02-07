// https://leetcode.com/problems/robot-room-cleaner

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {0,1}, {1,0}, {0, -1}}; //0: up. 1:right  2: down, 3:left
    unordered_set<string> visited; //pair<int, int>
    //Robot robot;
public:
    void goBack(Robot& robot) { //if possible move down one cell.
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
        
    }
    void backtrack(int row, int col, int d, Robot& robot) { 
        string key = to_string(row) + '-' + to_string(col);
        visited.insert(key); //visited.
        robot.clean();
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for(int i=0; i<4; i++) { //the order is important since the idea is always to turn right
            int newD = (d+i) %4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];
            string new_key = to_string(newRow) + '-' + to_string(newCol);
            if((visited.find(new_key)==visited.end()) && robot.move() ) { //not visited and can move.
                backtrack(newRow, newCol, newD, robot);
                goBack(robot);
            }
            robot.turnRight();
        };
    }

    void cleanRoom(Robot& robot) { //backtracking. 1 represents an empty slot.
        //this->robot = robot;
        backtrack(0, 0, 0, robot); //row:0, col: 0, dir: 0, up
    }
};