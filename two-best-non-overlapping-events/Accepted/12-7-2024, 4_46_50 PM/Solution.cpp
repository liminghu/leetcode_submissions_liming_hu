// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //events[i] = [startTimei, endTimei, valuei].
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; //pair: end, val.
        sort(events.begin(), events.end());
        int maxVal = 0;
        int maxSum = 0;
        for(auto& event: events) {
            while(!pq.empty() && pq.top().first <event[0] ) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }
        return maxSum;
    }
};