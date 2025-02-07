// https://leetcode.com/problems/seat-reservation-manager

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<>> seats;
public:
    SeatManager(int n) {
        for(int i=1; i<=n; i++)
            seats.push(i);
    }
    
    int reserve() {
        if(seats.empty())
            return 0;
        int t = seats.top();
        seats.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */