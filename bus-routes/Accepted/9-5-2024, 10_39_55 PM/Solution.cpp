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
        if(source == target )
            return 0;
        int n_bus = routes.size();
        unordered_map<int, vector<int>> mp;//bus_stop_idx, {bus_idx}
        for(int bus=0; bus<n_bus; bus++) {
            for(auto stop: routes[bus]) 
                mp[ stop ].push_back(bus); //bus_stop_idx, {bus_idx}
        };

        int res = 0;
        queue<int> q_bus;
        unordered_set<int> visited; //bus used before.
        for(auto bus: mp[source]) {//{bus_idx}
            q_bus.push(bus);
            visited.insert(bus);
        }

        int busCount = 1;
        while(!q_bus.empty()) {
            int size = q_bus.size(); //how many buses.

            for(int i=0; i<size; i++) { //try all the possible buses.
                int cur_bus = q_bus.front();
                q_bus.pop();
                for(auto stop: routes[cur_bus]) { //bus stops.
                    if(stop == target ) 
                        return busCount;
                    for(auto next_bus: mp[ stop ]) { //{bus_idx}: buses pass this stop.
                        if(visited.count(next_bus) == 0) { //the bus is not used.
                            q_bus.push(next_bus);
                            visited.insert(next_bus);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};