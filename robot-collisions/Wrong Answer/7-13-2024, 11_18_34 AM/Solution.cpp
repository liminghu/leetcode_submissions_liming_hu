// https://leetcode.com/problems/robot-collisions

/*There are n 1-indexed robots, each having a position on a line, health, and movement direction.
You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is 
either 'L' for left or 'R' for right). All integers in positions are unique.
All robots start moving on the line simultaneously at the same speed in their given directions. If two 
robots ever share the same position while moving, they will collide.
If two robots collide, the robot with lower health is removed from the line, and the health of the other 
robot decreases by one. The surviving robot continues in the same direction it was going. If both robots 
have the same health, they are both removed from the line.
Your task is to determine the health of the robots that survive the collisions, in the same order that the 
robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. 
If there are no survivors, return an empty array.
Return an array containing the health of the remaining robots (in the order they were given in the input), 
after no further collisions can occur.
Note: The positions may be unsorted.
*/
struct robot {
    int position;
    int health;
    char direction;
    int id;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        /* 
            1 <= positions.length == healths.length == directions.length == n <= 105
            1 <= positions[i], healths[i] <= 109
            directions[i] == 'L' or directions[i] == 'R'
            All values in positions are distinct
        */
        
        stack<robot> st; //moving direction stack.
        int sz = directions.length();
        vector<robot> robots(sz, robot());
        for(int i=0; i<sz; i++) {
            robots[i].id = i;
            robots[i].position = positions[i];
            robots[i].health = healths[i];
            robots[i].direction = directions[i];
        };

        sort(robots.begin(), robots.end(), [](robot first, robot second) {return first.position <= second.position;});
        for(int i=0; i<sz; i++) {
            //right: open; left: close.
            if(!st.empty()) {
                robot robot_top = st.top();
                if(robot_top.direction == 'R' && robots[i].direction == 'L') {//collide.
                    st.pop();
                    if(robot_top.health < robots[i].health) {
                        robot cur_robot = robots[i];
                        cur_robot.health--;
                        st.push(cur_robot);
                    } else if(robot_top.health == robots[i].health) {
                    } else if(robot_top.health > robots[i].health) {
                        robot_top.health--;
                        st.push(robot_top);
                    };
                } else //no collide
                    st.push(robots[i]);
            } else
                st.push(robots[i]);  
        }
        vector<robot> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        };
        sort(ans.begin(), ans.end(), [](robot first, robot second){return first.id <= second.id;} );
        vector<int> health;
        for(int i=0; i<ans.size(); i++) {
            health.push_back(ans[i].health);
        };

        return health;
    }
};