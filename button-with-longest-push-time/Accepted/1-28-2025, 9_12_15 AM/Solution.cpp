// https://leetcode.com/problems/button-with-longest-push-time

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        //events[i] = [indexi, timei], The array is sorted in increasing order of time.
        int smallestIdx = events[0][0];
        int LongestTime = events[0][1];
        for(int i=1; i<events.size(); i++) {
            int indexi = events[i][0];
            int timei = events[i][1];
            int prevTime = events[i-1][1];
            int pressT = timei - prevTime;
            if(pressT > LongestTime) {
                LongestTime = pressT;
                smallestIdx = indexi;
            } else if(pressT == LongestTime) {
                smallestIdx = min(smallestIdx, indexi);
            };
        };
        return smallestIdx;
    }
};