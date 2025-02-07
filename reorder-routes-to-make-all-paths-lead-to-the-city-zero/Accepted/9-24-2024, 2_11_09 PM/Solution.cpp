// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two 
different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in 
one direction because they are too narrow.
Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number 
of edges changed.
It's guaranteed that each city can reach city 0 after reorder.
2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
 */
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n, 0); // n cities.
        vector<vector<int>> adj(n);
        vector<vector<int>> back(n);
        int ans = 0;
        for(auto c: connections) {
            adj[ c[0] ].push_back(c[1]); // there is a road from c[0] to c[1].
            back[ c[1] ].push_back( c[0] );  //there is a city c[0] back to c[1].
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = 1;

            //change dir for all arrows facing out.
            for(auto a: adj[cur] ) { //from the city cur to ...
                if(!visited[a]) {
                    ans++;
                    q.push(a);
                }
            }
            for(auto b: back[cur]) { //the cities back to cur
                if(!visited[b])
                    q.push(b);
            }
        }
        return ans;

    }
};