// https://leetcode.com/problems/contains-duplicate

//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        bool ret = false;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i])== mp.end()) {
                mp[nums[i]] = true;
            } else
                return true;
        }

        return false;
        
    }
};