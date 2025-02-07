// https://leetcode.com/problems/subarrays-with-k-different-integers

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*  1 <= nums.length <= 2 * 104
            1 <= nums[i], k <= nums.length
        */
        return atMostK(nums, k) - atMostK(nums, k-1);
    }

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mp; //num, count
        int sz = nums.size();
        
        int count = 0;
        int i = 0;
        for(int j=0; j<sz; j++) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            count = count + j-i+1;
        }
        return count;
    }
};