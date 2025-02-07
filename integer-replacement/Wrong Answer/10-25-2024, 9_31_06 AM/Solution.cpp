// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        if(n==1)
            return 0;
        if(n%2==0)
            return 1+integerReplacement(n/2);
        if((n+1) % 4 == 0)
            return 1+ integerReplacement(n+1);
        else 
            return 1+ integerReplacement(n-1);
    }
};