// https://leetcode.com/problems/time-based-key-value-store

/*Design a time-based key-value data structure that can store multiple values for the same key at different time stamps 
and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
*/
//static auto cmp = [](pair<int, int> a, pair<int, int> b){ return a.first < b.first;};
class TimeMap {
    unordered_map<string, map<int, string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if( mp.find(key) == mp.end())
            return "";
        else {
            map<int, string> vs = mp[key];
            map<int, string>::iterator it = vs.upper_bound(timestamp);
            if(it == vs.begin())
                return "";
            it--;
            return it->second;
        }

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */