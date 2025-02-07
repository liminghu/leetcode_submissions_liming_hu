// https://leetcode.com/problems/minimum-time-to-complete-all-tasks

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) { //1 <= starti, endi <= 2000
        // tasks[i] = [starti, endi, durationi]
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b) {
            return a[1]<b[1];
        });
        vector<int> time(2001);
        for(int i=0; i<n; i++) {
            int starti = tasks[i][0];
            int endi = tasks[i][1];
            int durationi = tasks[i][2];
            int overlap = 0;
            for(int t = starti; t<=endi; t++)
                overlap += (time[t]==1);
            if(overlap >=durationi)
                continue;
            int diff = durationi - overlap;
            for(int t=endi; t>=starti; t--) {
                if(time[t]==0) {
                    time[t] = 1;
                    diff--;
                }
                if(diff==0)
                    break;
            }
        }
        int ret = 0;
        for(int i=1; i<=2000; i++)
            ret += (time[i]==1);
        return ret;
    }
};