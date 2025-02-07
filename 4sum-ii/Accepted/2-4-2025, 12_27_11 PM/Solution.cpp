// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        /*return the number of tuples (i, j, k, l) such that:
            0 <= i, j, k, l < n
            nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
        */
        //nums1[i] + nums2[j] = -( nums3[k] + nums4[l])
        map<int, int> mp;
        for(int k: nums1) {
            for(int l: nums2) {
                mp[k+l]++;
            }
        }
        int count = 0;
        for(int i:nums3) {
            for(int j:nums4) {
                count += mp[-(i+j)];
            }
        }
        return count;
    }
};