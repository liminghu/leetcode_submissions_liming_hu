// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> dict;
        for(auto& num:nums)
            dict[num]++;
        int res = 0;
        for(auto it:dict) {
            if(dict.count(it.first-1)>0) {
                res = max(res, it.second+dict[it.first-1]);
            };
        };
        return res;
    }
};