// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xornums1=0, xornums2=0;
        int m = nums1.size();
        int n = nums2.size();
        if(n%2==1) {
            for(auto num1:nums1)
                xornums1 ^= num1;
        }
        if(m%2==1) {    
            for(auto num2:nums2)
                xornums2 ^= num2;
        }

        return xornums1 ^ xornums2;
    }
};