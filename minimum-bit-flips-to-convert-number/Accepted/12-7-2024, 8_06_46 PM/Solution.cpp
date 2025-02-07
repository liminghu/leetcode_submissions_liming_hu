// https://leetcode.com/problems/minimum-bit-flips-to-convert-number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = start ^ goal;
        int res = 0;
        while(ret) {
            if(ret&1)
                res++;
            ret = ret>>1;
        };
        return res;
    }
};