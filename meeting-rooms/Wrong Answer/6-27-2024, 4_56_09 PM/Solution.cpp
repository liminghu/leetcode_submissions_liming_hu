// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
*/
    bool canAttendMeetings(vector<vector<int>>& intervals) { //0 <= intervals.length <= 104
                                                            //intervals[i].length == 2
                                                            //0 <= starti < endi <= 106
        bool overlapped = false;
        int sz = intervals.size();
        if( sz < 2 )
            return true;
        
        for(int i=0; i<sz; i++) {
            for(int j=i+1; j<sz; j++) {
                //if overlap
                                                //intervals[i][0] intervals[i][1]
                //intervals[j][0] intervals[j][1]

                //intervals[i][0] intervals[i][1]
                //                               intervals[j][0] intervals[j][1]
                if(intervals[j][0] > intervals[i][1] || intervals[j][1] < intervals[i][0])
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};