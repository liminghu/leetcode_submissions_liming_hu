// https://leetcode.com/problems/design-hashmap

class MyHashMap {
    vector<vector<pair<int,int>>> mp;
    const int size = 10000;
public:
    MyHashMap() {
        mp.resize(size);
        
    }
    
    void put(int key, int value) {
        int index = key % size;
        vector<pair<int,int>>& row = mp[index];
        for(auto iter = row.begin(); iter!=row.end(); iter++) {
            if(iter->first == key) {
                iter->second = value;
                return;
            }
        }
        row.push_back({key, value});
    }
    
    int get(int key) {
        int index = key % size;
        vector<pair<int,int>>& row = mp[index];
        for(auto iter = row.begin(); iter!=row.end(); iter++) {
            if(iter->first == key)              
                return iter->second;
        }
        return -1;
        
    }
    
    void remove(int key) {
       int index = key % size;
        vector<pair<int,int>>& row = mp[index];
        for(auto iter = row.begin(); iter!=row.end(); iter++) {
            if(iter->first == key) {              
                row.erase(iter);
                return;
            }
        }       
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */