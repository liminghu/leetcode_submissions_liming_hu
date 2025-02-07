// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
map<int,int>bookingCount; //sorted.
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        bookingCount[start]++;
        bookingCount[end]--;
        int overlap = 0;
        int maxOverlap = 0;
        for(pair<int,int> booking: bookingCount) { //line sweep.
            overlap += booking.second; //number. -number
            maxOverlap = max(maxOverlap, overlap);
        }
        return maxOverlap;        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */