// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        vector<int> ret;
        for(auto item:mp) {
            if(item.second > nums.size()/3)
                ret.push_back(item.first);
        };
        return ret;
    }
};