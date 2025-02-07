// https://leetcode.com/problems/number-of-great-partitions

/*
You are given an array nums consisting of positive integers and an integer k.
Partition the array into two ordered groups such that each element is in exactly 
one group. A partition is called great if the sum of elements of each group is 
greater than or equal to k.
Return the number of distinct great partitions. Since the answer may be too large, 
return it modulo 109 + 7.
Two partitions are considered distinct if some element nums[i] is in different groups 
in the two partitions.
*/
using LL = long long;
class Solution {
private:
    //from the first i elements, how many diff partitions s.t. the sum of grp A is s.
    LL dp[1001][1001]; //1 <= nums.length, k <= 1000. 
    LL M = 1e9+7;
public:
    int countPartitions(vector<int>& nums, int k) {
        /*  1 <= nums.length, k <= 1000
            1 <= nums[i] <= 109
        */
        LL sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum < 2*k)
            return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        dp[0][0] = 1; // for 0 element, there is 1 partition for the sum of 0.
        for(int i=1; i<=n; i++) {
            for (int s=0; s<k; s++) {
                dp[i][s] += dp[i-1][s]; // nums[i] is not selected.
                if( s >= nums[i] )
                    dp[i][s] += dp[i-1][ s- nums[i] ];
                dp[i][s] %= M;
            }
        }
        LL invalid = 0;
        for (int s=0; s<k; s++) {
            invalid = ( invalid + dp[n][s] ) % M; //if sum < k they are invalid.
        }
        LL total = 1;
        for(int i=0; i<n; i++) {
            total = (total*2) % M; // 2 ^ n;
        };
        return (total - 2*invalid + M ) %M;
    }
};