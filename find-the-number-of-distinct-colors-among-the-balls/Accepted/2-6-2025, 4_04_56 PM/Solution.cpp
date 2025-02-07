// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

/*
You are given an integer limit and a 2D array queries of size n x 2.
There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. 
For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, 
you need to find the number of distinct colors among the balls.
Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
Note that when answering a query, lack of a color will not be considered as a color.
1 <= limit <= 109
1 <= n == queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= limit
1 <= queries[i][1] <= 109
 */
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) { //queries: ball, color
        int n = queries.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> ball_color;   //ball, color.
        unordered_map<int, int> color_ball;  //color, num of balls ....
        for(int i=0; i<n; i++) {
            int ball_i = queries[i][0];
            int color_i = queries[i][1];

            if(ball_color.find(ball_i)!= ball_color.end()) { //it has been colored before.
                int prevcolor = ball_color[ball_i];
                color_ball[prevcolor]--;
                if(color_ball[prevcolor] == 0) 
                    color_ball.erase(prevcolor);   
            } 
            
            ball_color[ball_i] = color_i;  
            color_ball[color_i]++;   //color, ball
            ans[i] = color_ball.size();
        };

        return ans;
    }
};