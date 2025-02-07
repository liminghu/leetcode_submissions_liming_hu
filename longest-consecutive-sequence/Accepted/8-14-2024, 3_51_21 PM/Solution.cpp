// https://leetcode.com/problems/longest-consecutive-sequence

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
            0 <= nums.length <= 105
            -109 <= nums[i] <= 109
        */
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int x:s) {
            if(s.find(x-1)== s.end()) { //x is the head.
                int count = 0;
                while(s.find(x)!= s.end()) {
                    count++;
                    x++;
                }
                res = max(res, count);
            }
        }
        return res;

    }
};