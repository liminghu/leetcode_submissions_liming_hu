// https://leetcode.com/problems/design-hit-counter

class HitCounter {
private:
    map<int,int> hits;  //sorted increasing
public:
    HitCounter() {
        hits = map<int,int>();
        
    }
    
    void hit(int timestamp) {
        if(hits.find(timestamp)!=hits.end())
            hits[timestamp]++;  //o(logn)
        else
            hits[timestamp]=1;
    }
    
    int getHits(int timestamp) {
        int ans=0;
        // [first, last] that is greater than value
        map<int,int>::iterator up = hits.upper_bound(timestamp-300);
        while(up!=hits.end()) {
            ans += up->second;
            up++;
        }
        return ans;

    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */