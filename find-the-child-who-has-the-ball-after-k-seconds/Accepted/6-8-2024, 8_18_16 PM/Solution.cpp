// https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds

class Solution {
public:
    int numberOfChild(int n, int k) { //Return the number of the child who receives the ball after k seconds.
    //n-1 seconds front left to right.

    //2 <= n <= 50
        int rounds = k/(n-1); // 5/2 = 2   6/4 =1
        int left = k % (n-1); //1          2

        int ans = 0;
        if (rounds % 2 == 0 ) { //even: left to right: 
            ans = left;
        } else { //right to left. 
            ans = (n-1)-left;
        }
        return ans;
        
    }
};