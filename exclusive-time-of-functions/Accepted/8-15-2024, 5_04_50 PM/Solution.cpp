// https://leetcode.com/problems/exclusive-time-of-functions

/*On a single-threaded CPU, we execute a program containing n functions. Each function has a 
unique ID between 0 and n-1.
Function calls are stored in a call stack: when a function call starts, its ID is pushed onto 
the stack, and when a function call ends, its ID is popped off the stack. The function whose ID 
is at the top of the stack is the current function being executed. Each time a function starts 
or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string 
"{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function 
call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function 
call with function ID 1 ended at the end of timestamp 2. Note that a function can be called 
multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. 
For example, if a function is called twice, one call executing for 2 time units and another call 
executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents 
the exclusive time for the function with ID i.
*/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        /*  1 <= n <= 100
            1 <= logs.length <= 500
            0 <= function_id < n
            0 <= timestamp <= 109
            No two start events will happen at the same timestamp.
            No two end events will happen at the same timestamp.
            Each function has an "end" log for each "start" log.
        */
        
        //string: "{function_id}:{"start" | "end"}:{timestamp}"
        vector<int> et(n, 0);
        stack<pair<int, int>> process; //id, timestamp.
        for(int i=0; i<logs.size(); i++) {
            //string: "{function_id}:{"start" | "end"}:{timestamp}"
            string item = logs[i];
            int start_end_pos = logs[i].find(":",0);
            string id = logs[i].substr(0, start_end_pos);
            int id_i = stoi(id);
            int timestamp_pos = logs[i].find(":", start_end_pos+1);
            string start_end = logs[i].substr(start_end_pos+1, timestamp_pos-start_end_pos-1);
            string timestamp = logs[i].substr(timestamp_pos+1, logs[i].size() - timestamp_pos+1);
            int timestamp_i = stoi(timestamp); 
            //cout << id << "start_end= " << start_end << " timestamp= " << timestamp << endl;
            if(start_end == "start") {
                process.push({id_i, timestamp_i});
            } else if(start_end == "end") {
                pair<int, int> t = process.top();
                //id: t.first, timestamp: t.second
                if(t.first == id_i) {
                    et[t.first] += timestamp_i - t.second+1;
                    process.pop();                  
                    if(!process.empty()) {
                        int prevId = process.top().first;
                        et[prevId] -= timestamp_i - t.second+1;
                    }
                } else {
                   cout << id << "start_end= " << start_end << " timestamp= " << timestamp << endl;
                   cout << "sth wrong!"<<endl; 
                }
            }
        }

        return et;


    }
};