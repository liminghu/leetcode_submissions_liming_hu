// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
      if(n==0) return 1;
      if(n<0) {
        n=-n;
        x=1/x;
      };
      return (n%2 == 0)? myPow(x*x, n/2): x*pow(x*x,n/2);	  
    }
};