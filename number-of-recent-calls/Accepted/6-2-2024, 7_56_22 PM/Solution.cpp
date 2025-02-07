// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter { //a RecentCounter class which counts the number of recent requests within a certain time frame.
public:
    queue<int> calls;

    RecentCounter() { // Initializes the counter with zero recent requests.
        calls = queue<int>();
    }
    
    /* Adds a new request at time t, where t represents some time in milliseconds, 
    and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). 
    Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
    */
    int ping(int t) {
        calls.push(t);
        
        int f =0;
        while(!calls.empty()) {
            f = calls.front();
            if(t -f >3000)
                calls.pop();
            else
                break;
        };
        
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */