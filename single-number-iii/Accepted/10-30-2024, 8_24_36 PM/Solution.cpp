// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bitmask = 0;
        for(int num: nums)
            bitmask ^= num; // x^y
        long diff = bitmask & (-bitmask); //rightmost 1 bit diff between x, y
        int x = 0;
        for(int num: nums) {
            if((num & diff)!=0 )
                x ^= num;
        }
        return {(int)x, (int)(bitmask^x)};
    }
};