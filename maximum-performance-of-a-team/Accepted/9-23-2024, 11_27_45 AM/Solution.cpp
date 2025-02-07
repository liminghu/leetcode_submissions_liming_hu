// https://leetcode.com/problems/maximum-performance-of-a-team

/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n 
engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
1 <= k <= n <= 105
speed.length == n
efficiency.length == n
1 <= speed[i] <= 105
1 <= efficiency[i] <= 108
*/
using LL = long long;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //sum of its engineers' speeds multiplied by the minimum efficiency among its engineers
        vector<pair<int,int>> speedEffic;
        for(int i=0; i<n; i++)
            speedEffic.push_back({efficiency[i], speed[i]});
        sort(speedEffic.rbegin(), speedEffic.rend()); //decreasing..
        LL ret = 0;
        LL sum = 0;
        int minEffic = INT_MAX;
        priority_queue<int, vector<int>, greater<>> pq; //min top
        for(int i=0; i<n; i++) {
            minEffic = speedEffic[i].first;
            sum += speedEffic[i].second;
            pq.push(speedEffic[i].second);
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() <= k) {
                ret = max(ret, sum*minEffic );
            }
        }
        return ret % (1000000007);
    }
};