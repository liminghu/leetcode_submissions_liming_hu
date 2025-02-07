// https://leetcode.com/problems/non-overlapping-intervals

/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals 
you need to remove to make the rest of the intervals non-overlapping.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { //1 <= intervals.length <= 105
                                                                //intervals[i].length == 2
                                                                //-5 * 104 <= starti < endi <= 5 * 104
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        //[starti, endi] let's suppose the interval does not include endi.
  
        int ans = 0;
        for(int i=1; i<sz; i++) { //compare with i-1;
           int  starti = intervals[i][0],   endi = intervals[i][1];
           int  starti_ = intervals[i-1][0],   endi_ = intervals[i-1][1];
           //[starti_, endi_]
           //               [starti, endi]
           if(endi_ <= starti)
                continue;
            else {
           //[starti_,           endi_]
           //               [starti,        endi]           

           //[starti_,                             endi_]
           //               [starti,        endi]  
                intervals[i][1] =  min(endi_, endi); 
                ans++;                    

            }

        }   
        return ans;  
    }
};