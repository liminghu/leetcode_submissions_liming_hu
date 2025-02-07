// https://leetcode.com/problems/next-closest-time

/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. 
There is no limit on how many times a digit can be reused.
You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid.
 "1:34", "12:9" are all invalid.

Example 1:
Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:
Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 
Constraints:
time.length == 5
time is a valid time in the form "HH:MM".
0 <= HH < 24
0 <= MM < 60
*/
class Solution {
public:
    string nextClosestTime(string time) { //"HH:MM"
    vector<int> digits = {time[0]-'0', time[1]-'0', time[3]-'0', time[4]-'0'};
    int h = digits[0]*10 + digits[1];
    int m = digits[2]*10 + digits[3];
    vector<int> curr(4,  0);
    int now = toTime(h,m);
    int best = now;
    dfs( 0, digits, curr, now, best); //best: after 24 hours.
    string h_s = to_string(best/60);
    if(h_s.size()==1)
        h_s = "0" + h_s;
    string m_s = to_string(best%60);
        if(m_s.size()==1)
        m_s = "0" + m_s;
    string new_time = h_s + ":" + m_s;
    return new_time;

    /*    set<char> s(time.begin(), time.end());
        int hour = stoi(time.substr(0,2));
        int min  = stoi(time.substr(3,2));

        while(true) {
            min++;
            if(min==60) {
                min = 0;
                hour++;
                hour = hour % 24;
            }
            string h_s = to_string(hour);
            if(h_s.size()==1)
                h_s = "0" + h_s;
            string m_s = to_string(min);
            if(m_s.size()==1)
                m_s = "0" + m_s;
            string new_time = h_s + ":" + m_s;
            set<char> s2(new_time.begin(), new_time.end());
            if(includes(s.begin(), s.end(), s2.begin(), s2.end()))
                return new_time;
        }
        return time; */

    }
    void dfs(int depth, const vector<int>& digits, vector<int> cur, int time, int& best) {
        if(depth == 4) {
            int cur_h = cur[0]*10 + cur[1];
            int cur_m = cur[2]*10 + cur[3];
            if(cur_h > 23 || cur_m > 59 ) //invalid
                return; 
            int cur_time = toTime(cur_h, cur_m);
            if(timeDiff(time, cur_time) < timeDiff(time, best) )
                best = cur_time;
            return;
        }
        for(int digit: digits) { // 4. 
            cur[depth] = digit;
            dfs(depth+1, digits, cur, time, best); //update: depth, cur, best. same: digits, time. 
        }

    }
    int toTime(int h, int m) {
        return h*60 + m;
    }

    int timeDiff(int t1, int t2) {
        if(t1==t2)   return INT_MAX;
        return ((t2-t1) + 24*60 ) % (24*60);
    }
};