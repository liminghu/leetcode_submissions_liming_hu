// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
 map<int,int>events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = events.upper_bound(start); //The upper_bound(candidate_start) will find the event whose end is greater than the candidate_start (but not equal).
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */