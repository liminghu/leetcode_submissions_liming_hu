// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
        int k = nums.size();
        set<pair<int, int>> s;
        vector<int> pointers;
        for(int i=0; i<k; i++) {
            pointers.push_back(0);
            s.insert({nums[i][0], i});
        };
        vector<int> rets;
        int minRange = INT_MAX;
        while(true) {
            int sRange = s.rbegin()->first - s.begin()->first;
            if( sRange < minRange ) {
                minRange = sRange;
                rets = {s.begin()->first, s.rbegin()->first};
            }
            int i = s.begin()->second;
            pointers[i]++;
            if(pointers[i]== nums[i].size())
                break;
            s.erase(s.begin());
            s.insert({nums[i][pointers[i]], i});
        }
        return rets;
    }
};