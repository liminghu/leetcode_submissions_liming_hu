// https://leetcode.com/problems/minimum-processing-time

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        //The number of tasks to be executed is four times the number of processors
        int n = tasks.size();   //the number of processors: n/4
        //You are given an array processorTime representing the time each processor becomes available
        int np = processorTime.size();   //n = 4*np.
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int j = n-1;  //last task: from bigger task.
        int ans = 0;
        for(int i=0; i<np; i++) { //for each processor: for smaller
            int count = 0;
            while(count < 4) { //4 cores.
                ans = max(ans, processorTime[i]+tasks[j]);
                count++;
                j--;
            }
        }
        return ans;
    }
};