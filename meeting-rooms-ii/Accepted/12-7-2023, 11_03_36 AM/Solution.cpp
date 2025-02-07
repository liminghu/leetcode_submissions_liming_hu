// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> time_line;  //sorted
        for (size_t i=0; i<intervals.size(); i++) {
            time_line[intervals[i][0]]++;
            time_line[intervals[i][1]]--;
        }
        int max_rooms =0, rooms = 0;
        for(auto &time: time_line) {
            rooms += time.second;
            max_rooms = max(max_rooms, rooms);
        }
        return max_rooms;
    }
};