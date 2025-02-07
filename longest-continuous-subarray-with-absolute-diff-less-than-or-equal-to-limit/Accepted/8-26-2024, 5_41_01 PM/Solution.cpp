// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that 
the absolute difference between any two elements of this subarray is less than or equal to limit.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> set({nums[0]}); //sorted nondecreasing.
        int ret = 0;
        
        int j = 0;
        for(int i=0; i<nums.size(); i++) {
            while(*set.rbegin()-*set.begin() <=limit) {
                ret = max(ret, j-i+1);
                j++;
                if(j<nums.size())
                    set.insert(nums[j]);
                else
                    break;
            }
            if(j==nums.size())
                break;
            set.erase(set.find(nums[i]));
        }
        return ret;
    }
};