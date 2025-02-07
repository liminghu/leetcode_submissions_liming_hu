// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        //12*60 = 720
        int oneMinAngle = 360/60; // 6 degree.
        int oneHourAngle = 360/12; //30
        double minutesAngle = oneMinAngle*minutes;
        double hourAngle = (hour%12+minutes/60.0) * oneHourAngle;
        double diff = abs(hourAngle-minutesAngle);
        return min(diff, 360-diff);
    }
};