// https://leetcode.com/problems/two-sum-iii-data-structure-design

class TwoSum {
private:
    unordered_map<long,int> mp;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        mp[number]++;
    }
    
    bool find(int value) {
        for(auto item:mp) {
            if(mp.find(value-item.first) != mp.end() ) {
                if(item.first != value-item.first)
                    return true;
                if(item.first == value-item.first && item.second>=2)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */