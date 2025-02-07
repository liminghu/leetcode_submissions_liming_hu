// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) 
            mp[nums[i]]++;
        for(auto entry:mp) {
            int num = entry.first;
            int val = entry.second;
            if(k>0 && mp.find(num+k)!=mp.end())
                ans++;
            else if(k==0 && val > 1) 
                ans++;
        }
        return ans;
    }
};