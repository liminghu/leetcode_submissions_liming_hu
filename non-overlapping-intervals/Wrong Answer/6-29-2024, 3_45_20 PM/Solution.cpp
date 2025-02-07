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
        vector<bool> removed(sz, false);
        for(int i=0; i<sz-1; i++) {
           int  starti = intervals[i][0],   endi = intervals[i][1];
            for(int j=i+1; j<sz; j++) {
                int  startj = intervals[j][0],   endj = intervals[j][1];
                // [starti,   endi]
                //         [startj, endj]    remove                
                if( startj<endi  && (removed[i] == false) && (removed[j] == false) ) {
                    ans++;
                    removed[j] = true;
                } else if(endj<endi  && (removed[i] == false) && (removed[j] == false)) {
                // [starti,                 endi]   remove
                //         [startj, endj]     
                    ans++;
                    removed[i] = true;                      
                } else
                    continue;

            }
        }   
        return ans;  
    }
};