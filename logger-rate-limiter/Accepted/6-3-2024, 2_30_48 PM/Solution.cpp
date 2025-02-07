// https://leetcode.com/problems/logger-rate-limiter

class Logger {
private:
   /* struct message {
        string name;
        int timestamp;
    };
    vector<message> messages;*/
    unordered_map<string, int> messages;

public:
    Logger() {
        messages = unordered_map<string, int>();
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(messages.find(message)!= messages.end()) {
            if(messages[message] +10 <= timestamp)  {//can print
                messages[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else { //not found
            messages[message] = timestamp;
            return true;
        };
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */