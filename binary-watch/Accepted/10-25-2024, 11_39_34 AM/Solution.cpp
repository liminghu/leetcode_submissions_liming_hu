// https://leetcode.com/problems/binary-watch

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) { //number of LEDs turned on.
        // 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). 
        //Each LED represents a zero or one, with the least significant bit on the right.
        //Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM),
        // return all possible times the watch could represent. You may return the answer in any order.
        vector<string> rets;
        if(turnedOn >=9)
            return {};
        if(turnedOn == 0)
            return {"0:00"};
        
        for(int h=0; h<12; h++) {
            for(int m=0; m<60; m++) {
                bitset<10> b;
                b = h << 6 | m; //minutes has 6 bits.
                if(b.count() == turnedOn) {
                    string ret = to_string(h);
                    ret += (m<10)?":0": ":";
                    ret += to_string(m);
                    rets.push_back(ret);
                }
            }
        }
        return rets;
    }
};