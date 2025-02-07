// https://leetcode.com/problems/minimum-array-end

class Solution {
public:
    long long minEnd(int n, int x) { //1 <= n, x <= 10^8
        // x == nums[0] & nums[1] & ... & nums[n-1]
        long long result = x;
        while(--n) {
            result = (result+1) | x;
        }
        return result;

    }
    long long minEnd1(int n, int x) { //1 <= n, x <= 10^8
        //nums[i] < nums[i+1]
        // x == nums[0] & nums[1] & ... & nums[n-1]
        n--; //Reducing n by 1 to exclude x from the iteration
        long long result = x;
        long long mask;
        // Step 1: Iterate over each bit position with mask starting at 1 and
        // shifting left
        for(mask=1; n>0; mask <<=1) {
            // Step 2: If the corresponding bit in x is 0
            if( ( mask & x ) == 0 ) {
                // Set the bit in result based on the least significant bit of n
                result |= ( n & 1 ) * mask;
                n>>=1;// Shift n to the right by 1 to process the next bit
            }
        }
        return result;
    }
};