// https://leetcode.com/problems/maximum-xor-for-each-query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {//1 <= maximumBit <= 20
        int n = nums.size();
        int xorProduct = 0;
        for(int i=0; i<n; i++)
            xorProduct = xorProduct ^ nums[i];
        vector<int> ans(n, 0);
        int mask = (1<<maximumBit) -1;
        for(int i=0; i<n; i++) {
            ans[i] = xorProduct ^ mask;
            xorProduct =xorProduct ^ nums[n-1-i];
        }
        return ans;
    }
};