// https://leetcode.com/problems/most-profit-assigning-work

/*
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with 
difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.
For example, if three workers attempt the same job that pays $1, then the total profit will be $3. 
If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.
*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        /*  n == difficulty.length
            n == profit.length
            m == worker.length
            1 <= n, m <= 104
            1 <= difficulty[i], profit[i], worker[i] <= 105
        */
 /*       int n = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>> jobs; //difficulty, profit.

        for(int i=0; i<n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        };
        sort(worker.begin(), worker.end());
        sort(jobs.begin(), jobs.end());
        int ans = 0;
        int i=0;
        int best = 0;
        for(int level: worker) {
            while(i<n && level >= jobs[i].first) {
                best = max(best, jobs[i].second);
                i++;
            }
            ans += best;
        }
        return ans;*/
        const int N = 100000;
        vector<int> max_profit(N+1, 0);
        for(int i=0; i<difficulty.size(); i++) {
            max_profit[ difficulty[i] ] = max(max_profit[ difficulty[i] ], profit[i] );
        }
        for(int i=2; i<=N; i++) {
            max_profit[i] = max(max_profit[i], max_profit[i-1]);
        }
        int ans = 0;
        for(int level:worker) {
            ans+= max_profit[level];
        }
        return ans;
    }
};