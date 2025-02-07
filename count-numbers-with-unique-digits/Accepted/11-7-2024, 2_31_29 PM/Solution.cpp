// https://leetcode.com/problems/count-numbers-with-unique-digits

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ret = 1;
        for(int len =1; len<=n; len++)
            ret += choose(10, len) - choose(9, len-1);
        return ret;
    }
    int choose(int m, int n) {
        int ret = 1;
        for(int i=0; i<n; i++)
            ret *= m-i;
        return ret;
    }
};