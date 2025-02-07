// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> numsIndex(n);
        for(int i=0; i<n; i++) {
            numsIndex[i] = {nums[i], i};
        }
        sort(numsIndex.begin(), numsIndex.end());
        int width = 0;
        int maxWidth = 0;
        for(int i=0; i<n-1; i++) {
            if(numsIndex[i].second < numsIndex[i+1].second)
                width += numsIndex[i+1].second - numsIndex[i].second;
            else {
                maxWidth=max(maxWidth, width);
                width=0;
            }
        }
        return maxWidth;
    }
};