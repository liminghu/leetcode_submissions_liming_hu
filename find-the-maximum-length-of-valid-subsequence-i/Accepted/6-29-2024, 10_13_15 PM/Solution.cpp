// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

/*
You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) { //2 <= nums.length <= 2 * 105
                                            //1 <= nums[i] <= 107
        int parity = nums[0] % 2;
        int odd = 0;
        int even = 0;
        int even_odd = 0;
        for(int num: nums) {
            if(num%2 == 0)
                even ++;
            else 
                odd ++;
            
            if(num%2 == parity) {
                even_odd++;
                parity = 1-parity; //toggle the parity
            }
        }
        
        return max(even_odd, max(even, odd));
    }
};