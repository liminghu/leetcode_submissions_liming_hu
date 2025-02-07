// https://leetcode.com/problems/minimum-time-to-complete-all-tasks

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) { //1 <= starti, endi <= 2000
        // tasks[i] = [starti, endi, durationi]
        int n = tasks.size();
        /*Can We do this greedily?
            Q. If a task has the earliest end time would it be beneficial for me to run it as late as possible or as early as possible?
            A. Obviously I would want to run it as late so that it has maximum overlap (if any) with other tasks.
        */
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b) {
            return a[1]<b[1];
        });
        vector<int> time(2001);
        for(int i=0; i<n; i++) {
            int starti = tasks[i][0];
            int endi = tasks[i][1];
            int durationi = tasks[i][2];
            int overlap = 0;
            for(int t = starti; t <= endi; t++)
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