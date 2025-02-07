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
        unordered_map<int, int> mp; //num, count
        int sz = nums.size();
        int win_st = 0;
        int win_end = 0;
        int count = 0;
        while(count < k && win_end < sz) {
            if( mp[nums[win_end]] == 0 ) {
                count++;
            } 
            mp[nums[win_end]] += 1;
            win_end++;
        };

       if(count < k && win_end == sz)
            return 0;

        int res = 0;  //found the first good array.
        if(count == k)
            res = 1;
        while(win_end < sz && mp[nums[win_end]] >= 1) { //count == k
            mp[nums[win_end]]++;
            win_end++;
            res++;
        }
        win_end--;


        int i = 1;
        while(i < sz && win_end < sz) {
            win_st = i;   //remove nums[i]
            win_end = i;
            count = 0;
            mp.clear();
            while(count < k && win_end < sz) {
                if( mp[nums[win_end]] == 0 ) {
                    count++;
                } 
                mp[nums[win_end]] += 1;
                win_end++;
            }
            if(count < k && win_end == sz)
                return res;
            if(count == k)
                res += 1;
            while(win_end < sz && mp[nums[win_end]] >= 1) { //count == k
                mp[nums[win_end]]++;
                win_end++;
                res++;
            }
            win_end--;
            i++;
        };

        return res;        
    }
};