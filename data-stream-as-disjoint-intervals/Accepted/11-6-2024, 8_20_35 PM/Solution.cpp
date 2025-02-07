// https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
private:
    map<int, int> intervals; //start, end, sorted according to start.
public:
    SummaryRanges() {       
    }
    
    void addNum(int value) {
        int left = value; //default.
        int right = value;
        //Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
        auto small_entry = intervals.upper_bound(value); //small_entry.first > value
        
        if(small_entry != intervals.begin() ) {
            auto max_entry = small_entry;
            max_entry--; //max_entry.first <= value
            if( max_entry->second >= value ) //already in the set.
                return;
            if(max_entry->second == value - 1)
                left = max_entry->first;   //merge.
        }
        if(small_entry != intervals.end() && small_entry->first == value + 1) {//small_entry.first > value
            right = small_entry->second; //merge 
            intervals.erase(small_entry);
        };
        intervals[left] = right;

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> rets;
        for(auto p: intervals)
            rets.push_back({p.first, p.second});
        return rets;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */