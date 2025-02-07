// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        int mod = 1e9+7;
        int left = 0;
        int right = n-1;
        vector<int> pows(n,1);
        for(int i=1; i<n; i++) 
            pows[i] = (pows[i-1]*2)%mod;
        while(left <= right) {
            if(nums[left]+nums[right]>target)
                right--;
            else {
                res = ( res + pows[right-left] ) % mod;
                left++;
            }
        } 
        return res;
    }
};