// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
    long left = 0;
    long right = INT_MAX;
    //for(auto x: nums) {
    //    left = max(left, x);
    //    right += x;
    //}
    while (left < right ) {
        long mid = left+(right-left)/2;
        if(checkOK(nums, K, mid))
            right = mid;
        else
            left = mid+1;
    }
    return (int)left;
    /*    int N = nums.size();
        auto dp = vector<vector<long>>(N+1, vector<long>(K+1, INT_MAX));
        nums.insert(nums.begin(), 0);
        dp[0][0] = 0;
        for(int i=1; i<=N; i++) {
            for(int k=1; k<=min(K, i); k++) {
                long sum = 0;
                for(int j=i; j>=k; j--) {
                    sum += nums[j];
                    dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], sum));
                }
            }
        }
        return dp[N][K];*/
    }
    bool checkOK(vector<int>& nums, int K, long val) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > val) 
                return false;
            int j=i;
            long sum = 0;
            while(j<nums.size() && sum+(long)nums[j] <=val) {
                sum += (long)nums[j];
                j++;
            }
            count++;
            i=j-1;
        }
        return count <= K;
    }
};