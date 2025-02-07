// https://leetcode.com/problems/find-the-difference-of-two-arrays

/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0; i<nums1.size(); i++) 
            mp1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) 
            mp2[nums2[i]]++;
        unordered_set<int> ret1;
        unordered_set<int> ret2;

        for(int i=0; i<nums1.size(); i++) {
            if(mp2.find(nums1[i]) == mp2.end()) {
                ret1.insert(nums1[i]);
            }
        };
        for(int i=0; i<nums2.size(); i++) {
            if(mp1.find(nums2[i]) == mp1.end())
                ret2.insert(nums2[i]);
        };
        vector<vector<int>> rets;
        rets.push_back(vector<int>(ret1.begin(), ret1.end()));
        rets.push_back(vector<int>(ret2.begin(), ret2.end()));
        return rets;
    }
};