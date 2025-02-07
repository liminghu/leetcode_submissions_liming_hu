// https://leetcode.com/problems/contains-duplicate-ii

/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j 
in the array such that nums[i] == nums[j] and abs(i - j) <= k.
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            if( mp.find(nums[i]) != mp.end() ) {
                vector<int> idx = mp[ nums[i] ];
                if( abs(idx[idx.size()-1] - i) <= k )
                    return true;
            };
            mp[nums[i]].push_back(i);
        };
        return false;
    }
};