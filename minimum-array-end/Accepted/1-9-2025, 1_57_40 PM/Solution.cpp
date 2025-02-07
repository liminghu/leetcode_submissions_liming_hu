// https://leetcode.com/problems/minimum-array-end

class Solution {
public:
    long long minEnd(int n, int x) { //1 <= n, x <= 10^8
        //nums[i] < nums[i+1]
        // x == nums[0] & nums[1] & ... & nums[n-1]
        n--;
        long long result = x;
        long long mask;
        for(mask=1; n>0; mask <<=1) {
            if( (mask&x) == 0 ) {
                result |= (n&1)*mask;
                n>>=1;
            }
        }
        return result;
    }
};