// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);
        for(auto num:nums)
            count[ ( num % value + value ) % value ]++;
        int stop = 0;
        for(int i=0; i<value; i++) {
            if(count[i] < count[stop])
                stop = i;
        }
        return value*count[stop] + stop;
    }
};