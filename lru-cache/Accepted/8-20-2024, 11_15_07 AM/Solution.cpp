// https://leetcode.com/problems/lru-cache

class LRUCache {
private:
    int cap_;
    list<pair<int,int>> cache_; //key, value
    unordered_map<int, list<pair<int,int>>::iterator> mp_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto it = mp_.find(key);
        if( it == mp_.end() )
            return -1;
        
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second; //value.
        
    }
    
    void put(int key, int value) {
        auto it = mp_.find(key);
        if(it != mp_.end()) {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        if(cache_.size() == cap_) {
            auto node = cache_.back();
            mp_.erase(node.first); //key
            cache_.pop_back();
        }
        cache_.push_front({key, value});
        mp_[key] = cache_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */