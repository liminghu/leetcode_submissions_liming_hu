// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //intervals[i] = [lefti, righti]
        map<int, int> minGrps;
        for(auto& interval: intervals) {
            minGrps[interval[0]]++;
            minGrps[interval[1]+1]--;
        }
        int res = 0;
        int cur = 0;
        for(auto& item:minGrps) {
            cur += item.second;
            res = max(res, cur);
        }
        return res;
    }
};