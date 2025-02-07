// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

/*Longest Subarray With Maximum Bitwise AND
You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
In other words, let k be the maximum value of the bitwise AND of any subarray of nums. 
Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.
The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.
1 <= nums.length <= 105
1 <= nums[i] <= 106
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) { //1 <= nums[i] <= 106
        int n = nums.size();
        int curStreak = 0;
        int ret = 0;
        int maxVal = 0;
        for(int num: nums) {
            if(maxVal < num) {  //Bitwise AND results in a value that is always less than or equal to the operands
                maxVal = num;
                ret = 0;
                curStreak = 1;
            } else if(maxVal==num) {
                curStreak++;
            } else //maxVal > num
                curStreak = 0;
            ret = max(ret,curStreak);
        }
        return ret;

    }
};