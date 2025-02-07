// https://leetcode.com/problems/contiguous-array

//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //1 <= nums.length <= 105
        //nums[i] is either 0 or 1.
        int n = nums.size();
        unordered_map<int,int> mp; //sum, the earliest index;
        mp[0] = -1;

        int ret = 0;
        int presum = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==1)
                presum += 1;
            else
                presum -= 1; //0: -1;

            if(mp.find(presum)!=mp.end()) {
                ret = max(ret, i-mp[presum]);
            } else 
                mp[presum] = i;
        }

        return ret;
    }
};