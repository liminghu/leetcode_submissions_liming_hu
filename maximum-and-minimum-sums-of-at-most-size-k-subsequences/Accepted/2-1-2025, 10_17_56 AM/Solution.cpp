// https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences

class Solution {
    int M = 1e9+7;
public:
    int minMaxSums(vector<int>& nums, int k) { //1 <= k <= min(70, nums.length)
        int n = nums.size();
        long long ans = 0;
        vector<vector<int>> ncr(n+1, vector<int>(k+1, 0)); //n choose r
        ncr[0][0] = 1;
        for(int i=1; i<n; i++) {
            ncr[i][0] = 1;
            for(int r=1; r<=k; r++) 
                ncr[i][r] = ( ncr[i-1][r-1] + ncr[i-1][r] ) % M;
        };
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            for(int sz = 1; sz<=k; sz++) {
                long long minContrib = ( (long long)nums[i] * ncr[n-i-1][sz-1] ) % M; //nums[i] as the min
                long long maxContrib = ( (long long)nums[i] * ncr[i][sz-1] ) % M; //nums[i] as the max
                ans = ( ans + minContrib + maxContrib ) % M;
            }
        }
        return int(ans);
    }
};