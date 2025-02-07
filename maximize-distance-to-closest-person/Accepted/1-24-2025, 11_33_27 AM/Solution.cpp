// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
        int res = 0;
        int n = seats.size();
        int last = -1; //index of last seated seat.
        for(int i=0; i<n; i++) {
            if(seats[i] == 1) {
                if(last<0)
                    res = i;
                else 
                    res = max(res, (i-last)/2);
                last = i;
            }
        }
        res = max(res, n-1-last); //last is non neg.
        return res;
    }
};