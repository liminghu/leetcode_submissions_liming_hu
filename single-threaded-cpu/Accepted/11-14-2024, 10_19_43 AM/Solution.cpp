// https://leetcode.com/problems/single-threaded-cpu

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //pair: processing time, task idx.
        vector<array<int,3>> sortedTasks; //enqueue time, processing time, task idx.
        for(int i=0; i<tasks.size(); i++)
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> tasksProcessingOrder;
        long long currTime = 0;
        int taskIdx = 0;
        while(taskIdx <sortedTasks.size() || !pq.empty() ) {
            if(pq.empty() && currTime < sortedTasks[taskIdx][0])
                currTime = sortedTasks[taskIdx][0];
            while(taskIdx<sortedTasks.size() && currTime >= sortedTasks[taskIdx][0]) {
                pq.push({sortedTasks[taskIdx][1], sortedTasks[taskIdx][2]});
                taskIdx++;
            };
            if(!pq.empty()) {
                auto [processTime, idx] = pq.top();
                pq.pop();
                currTime += processTime;
                tasksProcessingOrder.push_back(idx);
            }
        }
        return tasksProcessingOrder;
    }
};