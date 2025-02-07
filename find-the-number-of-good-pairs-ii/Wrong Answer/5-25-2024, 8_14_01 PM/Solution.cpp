// https://leetcode.com/problems/find-the-number-of-good-pairs-ii

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<int> new_nums1;

        for(int i=0; i<nums1.size(); i++) {
            if (nums1[i]%k == 0)
                new_nums1.push_back(nums1[i]/k);
        }
        
        for(int i=0; i<new_nums1.size(); i++) {
             for(int j=0; j<nums2.size(); j++) {
                 if(nums2[j] != 0 && (abs(new_nums1[i])>abs(nums2[j])) && new_nums1[i]%(nums2[j]) == 0)
                     ans++;
             }            
        }
        return ans;
        
    }
};