// https://leetcode.com/problems/find-the-maximum-factor-score-of-array

class Solution {
public:
    long long maxScore(vector<int>& nums) {//1 <= nums.length <= 100; 1 <= nums[i] <= 30
        int n = nums.size();
        if(n==1)
            return nums[0] * nums[0];
        if(n==0)
            return 0;
        vector<long long> gcdPre(n, nums[0]), lcmPre(n, nums[0]), gcdSuf(n, nums[n-1]), lcmSuf(n, nums[n-1]);

        for(int i=1; i<n; i++)
            gcdPre[i] = gcd(gcdPre[i-1], nums[i]);
        for(int i=1; i<n; i++)
            lcmPre[i] = lcm(lcmPre[i-1], nums[i]);   

        for(int i=n-2; i>=0; i--)
            gcdSuf[i] = gcd(gcdSuf[i+1], nums[i]);
        for(int i=n-2; i>=0; i--)
            lcmSuf[i] = lcm(lcmSuf[i+1], nums[i]);       
        long long ans = max( {gcdPre[n-1]*lcmPre[n-1], gcdPre[n-2]*lcmPre[n-2], gcdSuf[1]*lcmSuf[1], gcdSuf[0]*lcmSuf[0]} );
        for(int i=1; i<n-1; i++) {
            long long a = lcm( lcmSuf[i-1], lcmPre[i+1] );
            long long b = gcd( gcdPre[i-1], gcdSuf[i+1] );
            ans = max( ans, a*b);
        }
        return ans;
    }
};
