// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
      long n2 = n; 
      if(x==1) return 1;
      if(n==0) return 1;
      if(x==0) return 0;
      if(n2<0) {
        n2=-n2;
        x=1/x;
      };
      return (n2%2 == 0)? myPow(double(x)*x, n2/2): x*pow(double(x)*x,n2/2);	  
    }
};