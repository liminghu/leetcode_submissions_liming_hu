// https://leetcode.com/problems/rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        //Assume arrk to be an array obtained by rotating nums by k positions clock-wise.
        //F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
        int rets = INT_MIN;
        int fk = 0;
        int sum = 0;
        for(int i= 0; i<n; i++) {
            fk += i* nums[i];
            sum += nums[i];
        };
        rets = max(rets, fk);
        for(int k=1; k<n; k++) {
            fk += sum - n * nums[(n-k) % n];
            rets = max(rets, fk);
        }
        return rets;
    }
};