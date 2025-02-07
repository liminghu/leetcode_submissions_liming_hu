// https://leetcode.com/problems/find-the-maximum-factor-score-of-array

class Solution {
public:
    long long maxScore(vector<int>& nums) {//1 <= nums.length <= 100; 1 <= nums[i] <= 30
        int n = nums.size();
        if(n==1)
            return nums[0] * nums[0];
        vector<long long> gcdPre(n), lcmPre(n), gcdSuf(n), lcmSuf(n);
        gcdPre[0] = nums[0];
        lcmPre[0] = nums[0];
        gcdSuf[n-1] = nums[n-1];
        lcmSuf[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
            gcdPre[i] = gcd(gcdPre[i-1], nums[i]*1LL);
        for(int i=1; i<n; i++)
            lcmPre[i] = (lcmPre[i-1]*nums[i]*1LL)/gcd(lcmPre[i-1],nums[i]*1LL);   
        for(int i=n-2; i>=0; i--)
            gcdSuf[i] = gcd(gcdSuf[i+1], nums[i]*1LL);
        for(int i=n-2; i>=0; i--)
            lcmPre[i] = (lcmPre[i+1]*nums[i]*1LL)/gcd(lcmPre[i+1],nums[i]*1LL);       
        long long ans = max( {gcdPre[n-1]*lcmPre[n-1], gcdSuf[0]*lcmSuf[0], gcdPre[n-2]*lcmPre[n-2], gcdSuf[1]*lcmSuf[1]} );
        for(int i=1; i<n-1; i++)
            ans = max( ans, gcd( gcdPre[i-1], gcdSuf[i+1] ) * ( (lcmSuf[i+1]) /gcd( lcmSuf[i+1], lcmPre[i-1] ) * lcmPre[i-1] ) );
        return ans;
    }
};
