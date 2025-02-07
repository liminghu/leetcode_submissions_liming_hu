// https://leetcode.com/problems/cheapest-flights-within-k-stops

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such 
route, return -1.
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); 
        for(int i=0; i<flights.size(); i++) {
            int from_i  = flights[i][0];
            int to_i    = flights[i][1];
            int price_i = flights[i][2];
            adj[ from_i ].push_back( { to_i, price_i } );
        };
        vector<int> stops(n, INT_MAX); //from src to city i, how many stops.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //min
        //price_from_src_city, city, number_of_stops_from_src_city
        pq.push({0, src, 0});
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int cur_price = t[0];
            int cur_city  = t[1];
            int cur_steps = t[2];
            //If cur_steps > stops[cur_city], then we already visited this node with fewer steps earlier, so ignore the current triplet and move on.
            if(cur_steps > stops[cur_city] || cur_steps > k+1) //k+1 flights maximum.
                continue;
            stops[cur_city] = cur_steps;
            if(cur_city == dst)
                return cur_price;
            for(auto [neighbor, price]: adj[cur_city]) {
                pq.push({cur_price + price, neighbor, cur_steps+1});
            }
        }
        return -1;

    }
};