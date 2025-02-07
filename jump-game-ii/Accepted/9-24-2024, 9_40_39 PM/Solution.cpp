// https://leetcode.com/problems/jump-game-ii

/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at
 nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
class Solution {
public:
    int jump(vector<int>& nums) {
       /* int n = nums.size();
        //nums[0]: 0+nums[i]
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        if(n==1)
            return 0;
        for(int i=0; i<n; i++) {
            for(int j=1; j<=nums[i]; j++) {
                if( i+j < n-1 )
                    dp[i+j] = min(dp[i+j], dp[i]+1);
                else //>=n-1
                    return dp[i]+1;
            }
        }
        return dp[n-1];*/

        int start = 0;
        int end = 0;
        int step = 0;
        if( nums.size() == 1 )
            return 0;
        while( start <= end ) { //[x] (x x) (o o o) (******) xxxxxxxxxxxxxxxxxxxxxxxxxxx
            int end_new = end;
            for(int i=start; i<=end; i++) {
                end_new = max( end_new, i + nums[i] );
                if( end_new >= nums.size()-1 )
                    return step+1;
            };
            step++;
            start = end+1;
            end = end_new;
        }
        return -1;
    }
};