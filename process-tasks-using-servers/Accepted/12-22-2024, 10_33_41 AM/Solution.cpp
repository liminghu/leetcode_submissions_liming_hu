// https://leetcode.com/problems/process-tasks-using-servers

using PII = pair<int,int>;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        //servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
        vector<int> rets(m, -1);
        priority_queue<PII, vector<PII>, greater<>> pq_free_server;   //weight, id
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq_busy_server; //time_available, weight, id.
        int i=0;
        for(auto server:servers) {
            pq_free_server.push({server, i});
            i++;
        };

        queue<int> jobs;

        for(int j=0; j<tasks.size(); j++) {
            jobs.push(j);
            while(!pq_busy_server.empty() && pq_busy_server.top()[0]<=j) {
                auto [t, w, idx] = pq_busy_server.top();
                pq_busy_server.pop();
                pq_free_server.push({w, idx});
            }
            while(!jobs.empty() && !pq_free_server.empty()) {
                int job = jobs.front();
                jobs.pop();
                auto [w,idx] = pq_free_server.top();
                pq_free_server.pop();
                rets[job] = idx;
                pq_busy_server.push({j+tasks[job], w, idx});
            }
        }
        while(!jobs.empty()) {
            int job = jobs.front();
            jobs.pop();
            auto [t, w, idx] = pq_busy_server.top();
            pq_busy_server.pop();
            rets[job] = idx;
            pq_busy_server.push({t+tasks[job], w, idx});                        
        }
        return rets;
    }
};