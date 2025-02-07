// https://leetcode.com/problems/count-special-subsequences

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        //indices (p, q, r, s)
        //nums[p] * nums[r] == nums[q] * nums[s]
        // nums[p]/nums[q] == nums[s]/nums[r]
        long long ret = 0;
        int  n = nums.size();
        unordered_map<double, int> cnt;
        for(int r=4; r<n-2; r++) {
            int q = r-2;
            for(int p=0; p<q-1; p++) 
                cnt[ 1.0* nums[p]/nums[q] ]++;
            for(int s=r+2; s<n; s++)
                ret += cnt[1.0*nums[s]/nums[r]];
        }
        return ret;
    }
};