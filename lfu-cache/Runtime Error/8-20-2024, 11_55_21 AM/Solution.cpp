// https://leetcode.com/problems/lfu-cache

class LFUCache {
private:
    unordered_map<int, int> key2value_;
    unordered_map<int, list<int>::iterator> key2iter_; //key.
    unordered_map<int,int> key2freq_;
    unordered_map<int, list<int>> freq2list_; //frequency
    int cap_;
    int minfreq_;
public:
    LFUCache(int capacity) {
        cap_ = capacity;
        minfreq_ = 0;
    }
    
    int get(int key) {
        if(key2value_.find(key) == key2value_.end())
            return -1;
        
        int f = key2freq_[key];
        freq2list_[f].erase(key2iter_[f]);

        freq2list_[f+1].push_back(key);
        key2iter_[key] = --freq2list_[f+1].end();
        key2freq_[key] = f+1;
        
        if(freq2list_[minfreq_].size() == 0)
            minfreq_++;
        
        return key2value_[key];
    }
    
    void put(int key, int value) {
        if( cap_ == 0 )
            return;
        if(get(key)!= -1) { //all the related ds will be updated in get.
            key2value_[key] = value;
            return;
        }

        if(key2value_.size() == cap_) {
            int k = freq2list_[minfreq_].front(); //key

            freq2list_[minfreq_].pop_front();
            key2value_.erase(k);
            key2iter_.erase(k);
            key2freq_.erase(k);

        }

            key2value_[key] = value;
            minfreq_ = 1;
            freq2list_[1].push_back(key);
            key2freq_[key] = 1;        
            key2iter_[key] = --freq2list_[1].end();
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */