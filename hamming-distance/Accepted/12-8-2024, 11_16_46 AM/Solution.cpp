// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = x ^ y;
        int res = 0;
        while(ret) {
            if((ret&1))
                res += 1;
            ret = ret>>1;
        }
        return res;
    }
};