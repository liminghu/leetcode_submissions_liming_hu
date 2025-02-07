// https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        //Return the sum of the digit differences between all pairs of integers in nums.
        int n = nums.size();
        int m = to_string(nums[0]).length();
        vector<vector<int>> count(m, vector<int>(10));
        long long res = 1ll * n *(n-1)/2 * m;
        for(int num: nums) {
            for(int k=0; k<m; k++) {
                res -= count[k][num%10];
                count[k][num%10]++;
                num /=10;
            }
        }
        return res;
    }
};