// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int first1 = -1;
        int second1 = -1;
        int i=0;
        int res = 0;
        while(n>0) {
            if((n&1) && first1 < 0) {
                first1 = i;
            } else if(first1>=0 && second1<0 && (n&1)) {
                second1 = i;
                res = max(res, abs(second1-first1));
                first1 = second1;
                second1 = -1; 
            }; 
            n = n>>1;
            i++;
        };
        return res;
    }
};