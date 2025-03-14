// https://leetcode.com/problems/find-the-number-of-good-pairs-ii

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        for(int i=0; i<nums1.size(); i++) {
             for(int j=0; j<nums2.size(); j++) {
                 if(nums2[j] != 0 && nums1[i]%(nums2[j]*k) == 0)
                     ans++;
             }            
        }
        return ans;
        
    }
};