// https://leetcode.com/problems/asteroid-collision

/*We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents 
its direction (positive meaning right, negative meaning left). Each asteroid moves 
at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode. Two 
asteroids moving in the same direction will never meet.
2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(asteroids[i] > 0) //move right, ok
                res.push_back(asteroids[i]);
            else { //move left.
                if(res.empty() || res.back() < 0) //ok, all move to the left
                    res.push_back(asteroids[i]);
                else if(abs(res.back()) <= abs(asteroids[i])) { //top move right.
                    if(abs(res.back()) < abs(asteroids[i])) //the current one can survive.
                        i--;
                    res.pop_back(); //destroy the top.
                };
            }
        }
        return res; //res must look like -s1, -s2, ....   si, sj, ...
    }
};