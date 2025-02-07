// https://leetcode.com/problems/minimum-processing-time

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        //The number of tasks to be executed is four times the number of processors
        int n = tasks.size();   //the number of processors: n/4
        //You are given an array processorTime representing the time each processor becomes available
        int np = processorTime.size();   //n = 4*np.
        sort(processorTime.begin(), processorTime.end()); //smaller first.
        sort(tasks.rbegin(), tasks.rend()); //bigger first.
        int j = 0;  //first task: from bigger task.
        int time = 0;
        for(int i=0; i<n; i++) { //for each processor
            int pTime = processorTime[i/4];
            int timeTaken = pTime + tasks[i];
            time = max(time, timeTaken);
        }
        return time;
    }
};