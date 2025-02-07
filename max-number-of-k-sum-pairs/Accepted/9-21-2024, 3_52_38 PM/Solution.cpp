// https://leetcode.com/problems/max-number-of-k-sum-pairs

/*
You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ret = 0;
        int sz = nums.size();
        if( sz <= 1 )
            return 0;
        unordered_map<int,int> mp;
        for(int i=0; i<sz; i++) {
            mp[ nums[i] ]++;
        };
        for(int i=0; i<sz; i++) {
            if(mp.find(nums[i]) != mp.end() && mp.find(k-nums[i]) != mp.end()) {
                if(nums[i] != k-nums[i] ) {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    mp[k-nums[i]]--;
                    if(mp[k-nums[i]] == 0)
                        mp.erase(k-nums[i]);
                    ret++;
                } else {
                    if(mp[nums[i]]>=2) {
                        mp[nums[i]] -= 2;
                        if(mp[nums[i]] == 0)
                            mp.erase(nums[i]);
                        ret++;
                    }
                }
            }
        };
        return ret;        
    }
};