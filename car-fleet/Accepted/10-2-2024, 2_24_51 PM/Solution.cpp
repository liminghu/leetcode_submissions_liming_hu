// https://leetcode.com/problems/car-fleet

/*
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
You are given two integer array position and speed, both of length n, where position[i] is the 
starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum 
speed of any car in the fleet.
If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
Return the number of car fleets that will arrive at the destination.
n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        //position[i] is the starting mile of the ith car and 
        //speed[i] is the speed of the ith car in miles per hour.
        
        //A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
        //A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
        vector<pair<int, int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({position[i], speed[i]});
        };
        sort(cars.begin(), cars.end());
        int count = 0;
        int i = n-1;
        while( i >= 0 ) {
            double Time2target = (target-cars[i].first)*1.0/cars[i].second;
            int j = i-1;
            while(j>=0 && (target-cars[j].first)*1.0/cars[j].second <= Time2target) //loop until j is not in the fleet of i.
                j--;
            count++; //we have a new fleet.
            i = j; //j is not the fleet.
        }
        return count;
    }
};