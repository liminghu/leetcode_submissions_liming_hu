// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
    map<int, int> events;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {//[startTime, endTime)
        auto it = events.lower_bound(startTime); //The lower_bound(candidate_start) will find the event whose end is greater or equal than the candidate_start
        if(it != events.end() && (*it).first < endTime) {
            return false;  //overlap
        }
        if(it!=events.begin()) {
            it = prev(it); //
            if(it->second > startTime)
                return false;
        }
        events.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */