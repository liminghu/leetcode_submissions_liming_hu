// https://leetcode.com/problems/soup-servings

/*
here are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:
Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an
 equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. 
 We stop once we no longer have some quantity of both types of soup.
Note that we do not have an operation where all 100 ml's of soup B are used first.
Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers
 within 10-5 of the actual answer will be accepted.

Example 1:
Input: n = 50
Output: 0.62500
Explanation: If we choose the first two operations, A will become empty first.
For the third operation, A and B will become empty at the same time.
For the fourth operation, B will become empty first.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * 
(1 + 1 + 0.5 + 0) = 0.625.

Example 2:
Input: n = 100
Output: 0.71875
 
Constraints:
0 <= n <= 109
*/
class Solution {
    unordered_map<string, double> mp;
public:
    double soupServings(int n) {
        if(n>5000)
            return 1;
        return dfs(n, n);
    }

    double dfs(int a, int b) {
        if(a<=0) {
            if( b<=0) 
                return 0.5;
            else if(b>0)
                return 1;
        } else { //a>0
            if( b<= 0 )
                return 0;
        }
        string encoder = to_string(a) + "_" + to_string(b);
        if(mp.find(encoder) !=mp.end())
            return mp[encoder];
        mp[encoder] =  0.25*dfs(a-100,b) + 0.25*dfs(a-75, b-25) + 0.25*dfs(a-50, b-50) + 0.25*dfs(a-25, b-75);
        return mp[encoder];
    }

};