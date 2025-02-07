// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //[t, t + duration - 1]
        int res = 0;
        int n = timeSeries.size();
        if(n==0)
            return 0;
        for(int i=0; i<n-1; i++) {
            res += min(timeSeries[i+1]-timeSeries[i], duration);
        }
        return res+duration;
    }
};