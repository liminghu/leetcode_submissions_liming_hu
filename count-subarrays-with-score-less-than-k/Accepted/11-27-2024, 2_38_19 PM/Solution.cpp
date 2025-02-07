// https://leetcode.com/problems/count-subarrays-with-score-less-than-k

using LL = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<LL> presum(n+1);
        for(int i=1; i<=n; i++)
            presum[i] = presum[i-1]+nums[i];
        LL ret = 0;
        for(int i=1; i<=n; i++) {
            if(nums[i]>=k)
                continue;
            LL left = 1; //number of count.
            LL right = i;
            while(left<right) {
                LL mid = right -(right-left)/2;
                if((presum[i]-presum[i-mid])*mid < k)  //qualified.
                    left = mid;
                else
                    right = mid-1;
            }
            ret += left;
        }
        return ret;
    }
};