// https://leetcode.com/problems/my-calendar-ii

class MyCalendarTwo {
map<int,int>bookingCount;
int maxOverlap = 2;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bookingCount[start]++;
        bookingCount[end]--;
        int overlap = 0;
        for(pair<int,int> booking: bookingCount) {
            overlap += booking.second;
            if(overlap > maxOverlap) {
                bookingCount[start]--;
                bookingCount[end]++;    
                if(bookingCount[start]==0)
                    bookingCount.erase(start);
                if(bookingCount[end]==0)
                    bookingCount.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */