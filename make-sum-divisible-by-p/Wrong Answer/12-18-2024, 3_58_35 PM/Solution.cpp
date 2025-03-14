// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int need = 0;
        for(int num: nums)
            need = (need+num) % p;
        //Find the shortest array with sum % p = need.
        int cur = 0;
        unordered_map<int,int> prefix;
        int res = INT_MAX;
        for(int i=0; i<n; i++) {
            cur = (cur+nums[i])%p;
            prefix[cur] = i;
            int want = (cur-need+p)%p;
            if(prefix.count(want))
                res = min(res, i-prefix[want]);
        }
        return res!=INT_MAX? res:-1;
    }
};