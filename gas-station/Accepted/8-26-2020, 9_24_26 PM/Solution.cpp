// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int diff = 0;
      for (int i=0; i<gas.size(); ++i) {
        diff += gas[i]-cost[i];
      };
      if (diff < 0)
        return -1;
      else {
        int starting = 0; 
        int tank = 0;
        for (int i=0; i<gas.size(); ++i) {
          tank += gas[i]-cost[i];
          if (tank < 0) {
            starting = i+1;
            tank = 0;
          }
        };
        return starting;
      }
    }
};