// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        int ret = 0;
        for(auto item:mp) {
            if(item.second > 1)
                ret += (item.second-1) * (item.second)/2;
        }
        return ret;
    }
};