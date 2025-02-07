// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {};
        for(auto trip: trips) { //[numPassengersi, fromi, toi]
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }
        for(auto i=0; capacity>=0 && i<1001; i++)
            capacity -= stops[i];
        return capacity >=0;
    }
};