// https://leetcode.com/problems/connecting-cities-with-minimum-cost

/*
There are n cities labeled from 1 to n. You are given the integer n and an array connections where 
connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi 
(bidirectional connection) is costi.
Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. 
If it is impossible to connect all the n cities, return -1,
The cost is the sum of the connections' costs used.

 Example 1:
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

Example 2:
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
 
Constraints:
1 <= n <= 104
1 <= connections.length <= 104
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 105
*/
/*
There are n cities labeled from 1 to n. You are given the integer n and an array 
connections where connections[i] = [xi, yi, costi] indicates that the cost of 
connecting city xi and city yi (bidirectional connection) is costi.
Return the minimum cost to connect all the n cities such that there is at 
least one path between each pair of cities. If it is impossible to connect 
all the n cities, return -1,
The cost is the sum of the connections' costs used.
1 <= n <= 104
1 <= connections.length <= 104
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 105
*/
typedef pair<int,int> PII;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) { //connections[i] = [xi, yi, costi]
        vector<vector<PII>> costs(n+1);
        vector<bool> visited(n+1, false);
        //vector<int> minCost(n+1, INT_MAX);

        for(auto connection: connections) {
            int xi = connection[0];
            int yi = connection[1];
            int costi = connection[2]; 
            costs[xi].push_back( {costi, yi} );
            costs[yi].push_back( {costi, xi} );
        };
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, 1}); // the cost from 0 to 1 is 0.
        int numVisited = 0;
        int res = 0;
        while(numVisited < n  && !pq.empty() ) {
            int cost = pq.top().first;
            int city = pq.top().second;
            pq.pop();
            if(visited[city])
                continue;
            visited[city] = true;
            numVisited++;
            res += cost;
            for(auto& conn: costs[city]) {
                cost = conn.first;
                city = conn.second;
                if(!visited[city] ) {
                    pq.push({cost, city});
                }
            }
        } 
        return numVisited == n? res : -1;
    }
};