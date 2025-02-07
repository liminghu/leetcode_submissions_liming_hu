// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
private:
    bool dp[201][20001]; //num of elements, possible sums. 1 <= nums.length <= 200; 1 <= nums[i] <= 100 200*100
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1)  
            return false;
        
        int n= nums.size();
        nums.insert(nums.begin(), 0);
        dp[0][0] = true;
        for(int i=1; i<=n; i++) {
            for(int s=0; s<=sum/2; s++) {
                dp[i][s] = dp[i-1][s] || ( s>=nums[i]  && dp[i-1][ s- nums[i] ]);
            }
        }

        return dp[n][sum/2];
        
    }
};