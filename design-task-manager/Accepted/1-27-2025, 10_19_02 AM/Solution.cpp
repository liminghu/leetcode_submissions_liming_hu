// https://leetcode.com/problems/design-task-manager

auto cmp = [](vector<int>& a, vector<int>& b ) {
    //[userId, taskId, priority]
    if(a[2]==b[2]) { //same priority
        if(a[1]==b[1]) //same task id.
            return a[0] < b[0];
        return a[1]<b[1]; //smaller task id.
    };
    return a[2] < b[2]; //smaller priority.
};
class TaskManager {
    unordered_map<int, pair<int,int>> taskId2Priority;
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        //[userId, taskId, priority],
        for(auto t: tasks) {
            pq.push(t);
            taskId2Priority[t[1]] = {t[0], t[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        vector<int> t = {userId, taskId, priority};
        pq.push(t);
        taskId2Priority[t[1]] = {t[0], t[2]};
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskId2Priority[taskId].first; 
        vector<int> t = {userId, taskId, newPriority};
        pq.push(t); //duplicate task id.
        taskId2Priority[t[1]] = {t[0], t[2]};        
    }
    
    void rmv(int taskId) {
        taskId2Priority[taskId].second = -1;     //[userId, priority]
    }
    
    int execTop() {
        while(!pq.empty() && taskId2Priority[pq.top()[1]].second != pq.top()[2]) 
                pq.pop();
        if(pq.empty())
            return -1;
        vector<int> t = pq.top(); ////[userId, taskId, priority]
        taskId2Priority[t[1]].second = -1;
        pq.pop();
        return t[0];   
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */