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
        int sz = nums.size();
        vector<int> dp(sz+1, 0); //length of the longest valid subsequence of nums end ith element.
        
        dp[0] = 1; 
        dp[1] = 1;  
        dp[2] = 2;
        //dp[2] = 2 or 1
        for(int i=3; i<=sz; i++) {
            //dp[i-1]    //dp[i-2]
            if ( (nums[i-1] + nums[i-2]) % 2  == (nums[i-2] + nums[i-3]) % 2)
                dp[i] = dp[i-1]+1;
            else {
                dp[i] = dp[i-2];
            }
        }
        
        return dp[sz];
        
    }
};