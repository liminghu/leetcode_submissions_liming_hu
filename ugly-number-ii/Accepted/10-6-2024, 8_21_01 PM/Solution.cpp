// https://leetcode.com/problems/ugly-number-ii

/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 
Constraints:
1 <= n <= 1690
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0;
        int j=0;
        int k=0;
        vector<int> rets({1});
        for(int t=0; t<n-1; t++) {
            int cur = min(rets[i]*2, min(rets[j]*3, rets[k]*5));
            rets.push_back(cur);
            if(cur == rets[i]*2)
                i++;
            if(cur == rets[j]*3)
                j++;
            if(cur == rets[k]*5)
                k++;                                
        }
        return rets.back();
    }
};