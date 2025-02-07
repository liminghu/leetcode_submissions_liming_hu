// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {//stations[i] = [positioni, fueli]
        int i = 0;
        int res = 0;
        priority_queue<int> pq;
        int cur = startFuel;
        for(res=0; cur < target; res++) {
            while(i<stations.size() && stations[i][0] <=cur) {
                pq.push(stations[i][1]);
                i++;
            };
            if(pq.empty())
                return -1;
            cur += pq.top();
            pq.pop();
        };
        return res;
    }
};