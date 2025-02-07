// https://leetcode.com/problems/largest-sum-of-averages

class Solution {
public:
/*
You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. 
The score of a partition is the sum of the averages of each subarray.
Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.
*/
    double largestSumOfAverages(vector<int>& nums, int K) { //1 <= nums.length <= 100; 1 <= nums[i] <= 104; 1 <= k <= nums.length
        double ans = 0.0;
        const int sz = nums.size();
        vector<vector<double>> dp_partition_k_sum(K+1, vector<double>(sz+1, 0.0));
        //at most k non-empty adjacent subarrays

        vector<double> sum(sz+1, 0.0);
        for(int i=1; i<=sz; i++) {
            sum[i] = sum[i-1]+nums[i-1];
            dp_partition_k_sum[1][i]=sum[i]/i;
        };
        
        // partition k will depends on partition k-1.       max( partion k-1 + average rest)       
        //  dp[k][i] = max(dp[k-1][j]    + avg(nums[j+1], nums[i]) )     j=                    i
        for(int k=2; k<=K; k++) {  //how many partitions.
            for(int i=k; i<=sz; i++)  { //how many elements.
                for(int j=k-1; j<i; j++) {                                    //where is the end of k-1 partition. j
                    dp_partition_k_sum[k][i] = max(dp_partition_k_sum[k][i], dp_partition_k_sum[k-1][j]+ (sum[i]-sum[j])/(i-j));
                }            
            }
        }

        return dp_partition_k_sum[K][sz];
    }
};