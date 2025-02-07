// https://leetcode.com/problems/maximum-profit-in-job-scheduling

/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.*/
struct work {
    int start;
    int end;
    int profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        /*  1 <= startTime.length == endTime.length == profit.length <= 5 * 104
            1 <= startTime[i] < endTime[i] <= 109
            1 <= profit[i] <= 104
        */
        vector<work> works;
        for(int i=0; i<profit.size(); i++) {
            work w;
            w.start = startTime[i];
            w.end = endTime[i];
            w.profit = profit[i];
            works.push_back(w);
        };
        sort(works.begin(), works.end(), [](work a, work b) {return a.end < b.end;});
        //define the dp[i] as the maximum profit taking elements from the suffix starting at i.
        vector<pair<int, int>> dp; //at ending time, the maximum profit.
        int ret = 0;
        for(int i=0; i<works.size(); i++) {
            int cur = ret;
            auto iter = upper_bound(dp.begin(), dp.end(), make_pair(works[i].start, INT_MAX));
            if( iter != dp.begin() )
                cur = max(cur, prev(iter,1)->second+works[i].profit);
            else 
                cur = max(cur, works[i].profit);
            dp.push_back( {works[i].end, cur} );
            ret = max(ret,cur);
        }
        return ret;

    }
};