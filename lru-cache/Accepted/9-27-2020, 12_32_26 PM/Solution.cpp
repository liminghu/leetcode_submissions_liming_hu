// https://leetcode.com/problems/lru-cache


class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
		const auto it = m_.find(key);
		if(it == m_.cend()) return -1;  //if key does not exist.
		//if it does exist, move the key to the front of the list.
		cache_.splice(cache_.begin(), cache_, it->second); //Transfers elements from x into the container, inserting them at position.
		return it->second->second; //it->second: pointer to the value.
    }
	
    void put(int key, int value) {
		const auto it = m_.find(key);
		//key already exists.
		if(it != m_.cend()) {
			it->second->second = value; //update value.
		    cache_.splice(cache_.begin(), cache_, it->second);
			return;
		};
		
		//key does not exist.
		//reach the capacity? remove the oldest element.
		if(cache_.size() == capacity_) {
			const auto& node = cache_.back();
			m_.erase(node.first);
			cache_.pop_back();
		}
		cache_.emplace_front(key, value);
		m_[key] = cache_.begin();
        
    }
private:
	int capacity_;
	list<pair<int, int>> cache_;
	unordered_map<int, list<pair<int,int>>::iterator> m_;
	
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */