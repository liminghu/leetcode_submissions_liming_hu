// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //[t, t + duration - 1]
        int res = 0;
        int n = timeSeries.size();
        if(n==0)
            return 0;
        int start = timeSeries[0];
        int end = timeSeries[0]+duration -1;
        if(n==1)
            return duration;
        for(int i=1; i<n; i++) {
            if(timeSeries[i] > end) {
                res+= end-start+1;
                start = timeSeries[i];
                end = timeSeries[i]+duration -1;
            } else {
                end = timeSeries[i]+duration -1;
            }
            if(i==n-1) {
                res += (end-start+1);
            }
        }
        return res;
    }
};