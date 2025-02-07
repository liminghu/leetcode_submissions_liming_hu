// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //[t, t + duration - 1]
        int res = 0;
        int n = timeSeries.size();
        int start = timeSeries[0];
        int end = timeSeries[0]+duration-1;
        for(int i=1; i<n; i++) {
            int new_pt_end = timeSeries[i]+duration-1;
            int new_pt_start = timeSeries[i];
            if(new_pt_start > end) 
                res += duration;
            else {
                end = new_pt_end;
            }
            if(i==n-1) 
                res += end-start+1;
        }
        return res;
    }
};