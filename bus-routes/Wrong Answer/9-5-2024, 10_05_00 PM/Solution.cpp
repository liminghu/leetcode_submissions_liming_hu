// https://leetcode.com/problems/bus-routes

/*
ou are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n_bus = routes.size();
        unordered_map<int, unordered_set<int>> mp;//bus_stop_idx, {bus_idx}
        for(int i=0; i<n_bus; i++) {
            for(int j=0; j<routes[i].size(); j++) {
                mp[ routes[i][j] ].insert(i); //bus_stop_idx, {bus_idx}
            }
        };

        if(source == target )
            return 0;
        int res = 0;
        queue<int> q_bus;
        for(auto bus: mp[source])
            q_bus.push(bus);
        vector<int> visited(n_bus, 0); //bus used before.
        int ret = 0;
        while(!q_bus.empty()) {
            int cur_bus = q_bus.front();
            visited[cur_bus] = 1;
            ret++;
            q_bus.pop();
            for(int i=0; i< routes[cur_bus].size(); i++) { //bus stops.
                if(routes[cur_bus][i] ==target ) {
                    return ret;
                };
                for(auto bus: mp[ routes[cur_bus][i] ]) { //{bus_idx}: buses pass this stop.
                    if(visited[bus] == 0) { //the bus is not used.
                        q_bus.push(bus);
                    }
                }
            }
        }
        return -1;

    }
};