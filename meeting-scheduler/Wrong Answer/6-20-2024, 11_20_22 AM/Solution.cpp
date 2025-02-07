// https://leetcode.com/problems/meeting-scheduler

/*
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.
*/
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        //sort
        int sz1 = slots1.size();
        int sz2 = slots2.size();
        sort(slots1.begin(), slots1.end(), [](vector<int> first, vector<int> second) { return first[0] < second[0];});
        sort(slots2.begin(), slots2.end(), [](vector<int> first, vector<int> second) { return first[0] < second[0];});
        
        int i=0; 
        int j=0;
        
        while(i<sz1 && j<sz2) {
            if (slots1[i][1] < slots2[j][0]+duration || slots1[i][1] - slots1[i][0]<duration) {  //first is behind
                i++;
            } else if (slots2[j][1] < slots1[i][0]+duration || slots2[j][1] - slots2[j][0]<duration) { //second is behind
                j++;
            } else {
                int start = 0;
                int end = 0;
                if(slots1[i][1] - slots2[j][0]>=duration && slots1[i][1]-slots1[i][0]>=duration && slots2[j][1]-slots2[j][0]>=duration)  { //first in front
                    if(slots2[j][0] > slots2[j][0] )
                        start = slots2[j][0];
                    else
                        start = slots1[i][0];
                        
                    end = start+duration;
                    return {start, end};
                };
                if(slots2[j][1] - slots1[i][0]>=duration && slots1[i][1]-slots1[i][0]>=duration && slots2[j][1]-slots2[j][0]>=duration) { //second in front
                    if(slots2[j][0] > slots2[j][0] )
                        start = slots2[j][0];
                    else
                        start = slots1[i][0];
                    end = start+duration;
                    return {start, end};
                };
                i++;
                j++;
            }
        }
        return {};
    }
};