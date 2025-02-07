// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //nums[i]-nums[j] = k or nums[i]-nums[j] = -k
        //nums[i] = nums[j]+k or nums[i] = nums[j]-k;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]+k)!=mp.end()) {
                count += mp[nums[i]+k];
            };
            if(mp.find(nums[i]-k)!=mp.end()) {
                count += mp[nums[i]-k];
            };            
        }
        return count/2;
    }
};