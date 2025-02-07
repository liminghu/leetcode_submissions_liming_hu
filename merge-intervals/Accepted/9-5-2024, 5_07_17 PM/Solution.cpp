// https://leetcode.com/problems/merge-intervals

class Solution {
public:
   static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>> diff;
     for(auto& interval:intervals) {
        diff.push_back({interval[0], 1});
         diff.push_back({interval[1], -1});
     };
     sort(diff.begin(), diff.end(), cmp);
     vector<vector<int>> result;
     int start=0, end=0;
     int sum = 0;
     for(int i=0; i<diff.size(); i++) {
        if(sum==0 && diff[i][1] == 1) {
            start = diff[i][0];
        }else if(sum ==1  && diff[i][1] == -1) {
            end = diff[i][0];
            result.push_back({start,end});
        }
        sum += diff[i][1];
     };
     return result;

     /*   sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(auto interval: intervals) {
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;*/
        
    }
};