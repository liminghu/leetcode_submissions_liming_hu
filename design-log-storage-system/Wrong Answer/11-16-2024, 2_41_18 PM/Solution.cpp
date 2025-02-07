// https://leetcode.com/problems/design-log-storage-system

class LogSystem {
    map<string, vector<int>> log_ids;
    unordered_map<string, int> idx;
public:
    LogSystem() {//Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59
        idx["Year"]   = 5;
        idx["Month"]  = 8;
        idx["Day"]    = 11;
        idx["Hour"]   = 14;
        idx["Minute"] = 17;
        idx["Second"] = -1;
    }
    
    void put(int id, string timestamp) {
        //Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59
        if(log_ids.find(timestamp)!=log_ids.end())
            log_ids[timestamp].push_back(id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int s = idx[granularity];
        vector<int> res;
        if( s != -1 ) { //2016:01:01:01:01:01
            start[s] = '0' - 1;
            end[s]   = '9' + 1; 
        }
        auto left  = log_ids.lower_bound(start); //Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
        auto right = log_ids.upper_bound(end);
        for(auto i = left; i != right; i=next(i)) {
            for(auto id:i->second)
                res.push_back(id);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */