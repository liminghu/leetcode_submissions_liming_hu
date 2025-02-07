// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
      if(x == -pow(2,31)) return 0;
	  bool pos = true;
	  
      if( x < 0 ) {
		x = - x;
		pos = false;
	  };
	  
	 
	  int rem = 0;
	  int sum = 0;
	  
      while( x > 0) {
		rem = x % 10;
		x = x / 10;  
		sum = sum * 10;
		sum += rem;
	  };
      
      sum= sum*10+rem;
	  
      if(!pos)
		sum = -sum;
	  return sum; 
    }
};
