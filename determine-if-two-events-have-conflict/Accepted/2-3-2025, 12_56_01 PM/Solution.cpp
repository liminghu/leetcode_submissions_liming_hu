// https://leetcode.com/problems/determine-if-two-events-have-conflict

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        //event1 = [startTime1, endTime1] and
        //event2 = [startTime2, endTime2].
        //HH:MM 24hrs
        string startTime1 = event1[0];
        int hs1 = stoi(startTime1.substr(0, 2));
        int ms1 = stoi(startTime1.substr(3, 2));
        string endTime1 = event1[1];
        int he1 = stoi(endTime1.substr(0, 2));
        int me1 = stoi(endTime1.substr(3, 2));  

        string startTime2 = event2[0];
        int hs2 = stoi(startTime2.substr(0, 2));
        int ms2 = stoi(startTime2.substr(3, 2));        
        string endTime2 = event2[1];
        int he2 = stoi(endTime2.substr(0, 2));
        int me2 = stoi(endTime2.substr(3, 2));        

        if(hs1*60+ms1 < hs2*60+ms2) {
            return hs2*60+ms2 <= he1*60+me1;
        } else if(hs1*60+ms1 > hs2*60+ms2) {
            return he2*60+me2 >= hs1*60+ms1;
        } return
            true;
    }
};