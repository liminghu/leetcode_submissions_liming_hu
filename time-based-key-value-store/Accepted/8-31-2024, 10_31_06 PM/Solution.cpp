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

/*1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.
*/

class TimeMap {
    //unordered_map<string, map<int, string>> mp;
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        //mp[key][timestamp] = value;
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
       /* if( mp.find(key) == mp.end())
            return "";
        else {
            map<int, string> vs = mp[key];
            map<int, string>::iterator it = vs.upper_bound(timestamp);
            if(it == vs.begin())
                return "";
            it--;
            return it->second;
        }*/

        if(mp.find(key)== mp.end())
            return "";
        if(timestamp < mp[key][0].first)
            return "";
        auto it = upper_bound(mp[key].begin(), mp[key].end(), make_pair(timestamp, ""), [](const pair<int, string> a, const pair<int, string> b){ return a.first < b.first;});
        if(it == mp[key].begin())
            return "";
        return prev(it)->second;

        /*int left = 0;
        int right = mp[key].size();

        while(left < right) {
            int mid = (left+right)/2;
            if(mp[key][mid].first <= timestamp) 
                left = mid+1;
            else
                right = mid;                
        }
        if(right == 0)
            return "";
            return mp[key][right-1].second;*/

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */