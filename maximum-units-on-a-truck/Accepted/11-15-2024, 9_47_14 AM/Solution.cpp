// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> b) {
        return a[1] > b[1];
    };
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for(auto box:boxTypes) {
            int nb = min(box[0], truckSize);
            ans += nb*box[1];
            truckSize -= nb;
            if(truckSize==0)
                break;
        }
        return ans;
    }
};