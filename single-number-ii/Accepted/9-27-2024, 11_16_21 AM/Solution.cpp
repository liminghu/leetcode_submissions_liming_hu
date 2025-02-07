// https://leetcode.com/problems/single-number-ii

/*
Given an integer array nums where every element appears three times except for one, which appears 
exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        };
        int loner = 0;
        for(auto entry:freq) {
            if(entry.second ==1)
                return entry.first;
        };
        return 0;
    }
};