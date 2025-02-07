// https://leetcode.com/problems/number-of-digit-one

class Solution {
public:
    int countDigitOne(int n) {
        int count1 = 0;
        for(long long i=1; i<=n; i*=10) {
            long long divider = i*10;
            count1 += (n/divider)*i + min( max(n % divider - i + 1, 0LL), i);
        }
        return count1;
    }
};