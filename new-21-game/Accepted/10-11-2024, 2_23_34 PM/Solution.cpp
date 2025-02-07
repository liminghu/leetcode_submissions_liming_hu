// https://leetcode.com/problems/new-21-game

/*
Alice plays the following game, loosely based on the card game "21".
Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number 
of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
Alice stops drawing numbers when she gets k or more points.
Return the probability that Alice has n or fewer points.
Answers within 10-5 of the actual answer are considered accepted.

Example 1:
Input: n = 10, k = 1, maxPts = 10
Output: 1.00000
Explanation: Alice gets a single card, then stops.

Example 2:
Input: n = 6, k = 1, maxPts = 10
Output: 0.60000
Explanation: Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.

Example 3:
Input: n = 21, k = 17, maxPts = 10
Output: 0.73278
 
Constraints:
0 <= k <= n <= 104
1 <= maxPts <= 104
*/
class Solution {
public:
    double new21Game(int N, int K, int W) { //Return the probability that Alice has n or fewer points.
        //Alice starts with 0 points and draws numbers while she has less than k points.
        //During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. 
        //Each draw is independent and the outcomes have equal probabilities.
        //Alice stops drawing numbers when she gets k or more points.
        /*point 0 initially
        while (point < K) {
            draw w  from [1, W] randomly 
            point += w
        }
        probability(point <= N) ?
        */

        /*  Before we reach point `i`, we draw `w`, i.e., our last point is `i - w` 
            probability to get i points = sum(probability to get i - w points * 1 / W) for w can be any of [1, W]
            where 0 <= i - w < K
        */
        //target probability = sum of prabability to get points [K, N]

        //corner case
       /* if(K==0)
            return 1;
        int maxPoint = K + W - 1;
        vector<double> prob(maxPoint+1, 0.0);
        prob[0] = 1;
        for(int i=1; i<=maxPoint; i++) {
            for(int w=1; w<=W; w++) {
                if(i-w>=0 && i-w < K ) 
                    prob[i] += prob[i-w]*1.0 / W; 
            }
        }

        double targetProb = 0;
        for(int i=K; i<=N; i++) 
            targetProb += prob[i];
        return targetProb;*/

        vector<double> dp(K+W, 0.0);
        for(int k=K; k<min(N+1, K+W); k++) { //N ......    K+W  
            dp[k] = 1.0;
        }
        double sum = min( N-(K-1), W );
        for(int k= K-1; k>=0; k--) {
            dp[k] = sum/double(W);
            sum += dp[k] - dp[k+W];
        }
        return dp[0];
    }
};