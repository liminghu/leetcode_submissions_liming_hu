// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for(int num: nums)
            bitmask ^= num; // x^y
        int diff = bitmask & (-bitmask); //rightmost 1 bit diff between x, y
        int x = 0;
        for(int num: nums) {
            if((num & diff)!=0 )
                x ^= num;
        }
        return {x, bitmask^x};
    }
};