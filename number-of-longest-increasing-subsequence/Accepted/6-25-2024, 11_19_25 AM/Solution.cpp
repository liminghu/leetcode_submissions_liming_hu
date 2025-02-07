// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        //dp[i] => s[1:i]里以s[i]结尾的、最长的递增子序列的长度
        vector<int> length(sz,1);
        vector<int> count(sz,1);

        if(sz==1)
            return 1;

        for(int i=0; i<sz; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {                    
                    if( length[j]+1 > length[i] ) {
                        length[i] = length[j]+1;
                        count[i] = 0;
                    }
                    if(length[j]+1 == length[i]) 
                        count[i] += count[j];
                }
            }            
        }
        int max_length = 0;
        for(int i=0; i<sz; i++)
            max_length = max(max_length, length[i]);

        int ret = 0;
        for(int i=0; i<sz; i++) {
            if(length[i]==max_length)
                ret+=count[i];
        }
        return ret;
    }
};