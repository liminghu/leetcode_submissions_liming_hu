// https://leetcode.com/problems/generate-random-point-in-a-circle

/*
Given the radius and the position of the center of a circle, implement the function randPoint which 
generates a uniform random point inside the circle.

Implement the Solution class:
Solution(double radius, double x_center, double y_center) initializes the object with the radius of 
the circle radius and the position of the center (x_center, y_center).
randPoint() returns a random point inside the circle. A point on the circumference of the circle is 
considered to be in the circle. The answer is returned as an array [x, y].
 
Example 1:
Input
["Solution", "randPoint", "randPoint", "randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
Output
[null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
Explanation
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint(); // return [-0.02493, -0.38077]
solution.randPoint(); // return [0.82314, 0.38945]
solution.randPoint(); // return [0.36572, 0.17248]
 
Constraints:
0 < radius <= 108
-107 <= x_center, y_center <= 107
At most 3 * 104 calls will be made to randPoint.
*/
class Solution {
public:
    double radius;
    double x_center;
    double y_center;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x0 = x_center - radius;
        double y0 = y_center - radius;
        while(true) {
            double xg = x0 + uni(rng) *2 * radius;
            double yg = y0 + uni(rng) *2 * radius;
            if((xg-x0)*(xg-x0) + (yg-y0)*(yg-y0) <= 2 * radius)
                return {xg, yg};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */