// https://leetcode.com/problems/total-cost-to-hire-k-workers

/*
You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last 
candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker 
because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have
 the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie 
by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.
1 <= costs.length <= 105 
1 <= costs[i] <= 105
1 <= k, candidates <= costs.length
*/
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pqLeft; //min
        priority_queue<int, vector<int>, greater<int>> pqRight; //min
        long long ret=0;
        int l = 0;
        int r = costs.size()-1;
        int count = 0;
        while(count < k) {
            while( pqLeft.size() < candidates && l <= r) { // l<=r to make sure that the candidate will not get into both queue, and always in the left queue.
                pqLeft.push(costs[l]);
                l++;
            };
            while(pqRight.size() < candidates && l <= r) {
                pqRight.push(costs[r]);
                r--;
            };
            int topLeft = pqLeft.size()>0? pqLeft.top(): INT_MAX;
            int topRight = pqRight.size()>0? pqRight.top(): INT_MAX;
            if( topLeft <= topRight ) { //Break the tie by the smallest index.
                ret += topLeft;
                pqLeft.pop();
            } else {
                ret += topRight;
                pqRight.pop();                
            }
            count++;
        }
        return ret;
    }
};