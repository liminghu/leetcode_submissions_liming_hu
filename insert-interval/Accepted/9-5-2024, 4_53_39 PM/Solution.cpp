// https://leetcode.com/problems/insert-interval

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
represent the start and the end of the ith interval and intervals is sorted in ascending order by 
starti. You are also given an interval newInterval = [start, end] that represents the start and 
end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() && !(intervals[i][0] > newInterval[1])) { //overlap.
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        result.push_back(newInterval);
        while(i<intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;

 
 /*       vector<vector<int>> q;
        for(auto interval: intervals) {
            q.push_back({interval[0], 1});
            q.push_back({interval[1], -1});
        };
        q.push_back({newInterval[0], 1});
        q.push_back({newInterval[1], -1});
        sort(q.begin(), q.end(), cmp); //first in, then out.
        int count = 0;
        int start, end;
        vector<vector<int>> result;
        for(auto x: q) {
            count += x[1];
            if(x[1] == 1 && count == 1) 
                start = x[0];
            else if(x[1] == -1 && count == 0 ) {
                end = x[0];
                result.push_back({start, end});
            }
        }
        return result;*/
    }

    bool isOverlap(vector<int> a, vector<int> b) {
               //[start_a      end_a]
               //                      [start_b      end_b]
               if(b[0] > a[1])
                    return false;
                //                                         [start_a      end_a]
               //                      [start_b      end_b]    
                if(b[1] < a[0])
                    return false;

                return true;               
    }

    vector<int> mergeIntervals(vector<int> a, vector<int> b) {
               //[start_a                                              end_a]
               //                      [start_b      end_b]
               vector<int> ret(2,0);
               if(a[1] >= b[0]  ) {
                    ret[0] = a[0]+1;
                    ret[1] = b[1];
               } else {
               //                               [start_a                end_a]
               //                      [start_b          end_b]       
                    ret[0] = b[0];
                    ret[1] = a[1];         
               }    
               return ret;    

    }
};