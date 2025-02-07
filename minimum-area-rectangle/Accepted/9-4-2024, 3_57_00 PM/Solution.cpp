// https://leetcode.com/problems/minimum-area-rectangle

/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of a rectangle formed from these points, with sides parallel 
to the X and Y axes. If there is not any such rectangle, return 0.
1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 4 * 104
All the given points are unique.
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto p: points) {
            mp[p[0]].insert(p[1]);
        };
        
        int ret = INT_MAX;
        for(int i=0; i<points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1==x2 || y1==y2) 
                    continue;
                int x3 = x2;
                int y3 = y1;
                int x4 = x1;
                int y4 = y2;
                if(mp[x3].find(y3) == mp[x3].end())
                    continue;
                if(mp[x4].find(y4) == mp[x4].end())
                    continue;    
                ret = min(ret, abs((x2-x1)*(y2-y1)));                   
            }
        }
        return ret==INT_MAX? 0:ret;
    }
};