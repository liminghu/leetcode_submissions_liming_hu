// https://leetcode.com/problems/count-integers-in-intervals

class CountIntervals {
map<int, int> intervals; //key: start, value: end.
int cnt = 0;
public:
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = intervals.upper_bound(left);
        if(it!=intervals.begin() && prev(it)->second >= left)
            it = prev(it);
        while(it!=intervals.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
            it = intervals.erase(it); //it points to its next.
        }
        cnt += right-left+1;
        intervals[left] = right;
        //cout << "left: " << left << " right: " << right << endl;
        //cout << "count:" << cnt << endl;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */