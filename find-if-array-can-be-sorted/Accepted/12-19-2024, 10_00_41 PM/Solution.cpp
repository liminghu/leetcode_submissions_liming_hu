// https://leetcode.com/problems/find-if-array-can-be-sorted

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int curMax = 0; //Track the largest number in the current segment (with equal number of set bits), fail fast if any number is less than the previous segment's largest.
        int prevMax = 0;
        int curBits = 0;
        for(int num: nums) {
            int bits = countBits(num);
            if(bits!=curBits) {
                curBits = bits;
                prevMax = curMax;
            }
            if(num<prevMax)
                return false;
            curMax = max(curMax, num);
        }
        return true;
    }
    int countBits(int num) {
        int ret = 0;
        while(num>0) {
            if((num&1) == 1)
                ret++;
            num = num>>1;
        }
        return ret;
    }
};