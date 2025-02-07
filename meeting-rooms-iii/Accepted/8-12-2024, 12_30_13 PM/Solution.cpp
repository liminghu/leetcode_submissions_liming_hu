// https://leetcode.com/problems/meeting-rooms-iii

/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the 
half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the 
same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.
*/
using LL = long long;
using PLI = pair<LL, int>; //<avilable time, index>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<PLI, vector<PLI>, greater<PLI>> busy; //min queue.
        priority_queue<int, vector<int>, greater<int>> free; //free available room, index.
        for(int i=0; i<n; i++)
            free.push(i);
        
        vector<LL> count(n, 0);

        for(int i=0; i<meetings.size(); i++) {
            LL start = meetings[i][0];
            LL end = meetings[i][1];

            while(!busy.empty() && busy.top().first <= start) { //put all the busy meetings which had finished into free.
                free.push(busy.top().second);
                busy.pop();
            };

            if(!free.empty()) {
                int idx = free.top();
                count[idx]++;
                free.pop();
                busy.push({end, idx});
            }else { //wait.
                auto [time, idx] = busy.top();
                count[idx]++;
                busy.pop();
                busy.push({time+end-start, idx});
            }
        } 

        return max_element(count.begin(), count.end()) - count.begin();

    }
};