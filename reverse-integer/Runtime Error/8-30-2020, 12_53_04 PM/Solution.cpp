// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
    try {
      if(x <= -(pow(2,31))) return 0;
	  if (x > int((pow(2, 31))-1)) return 0;
        
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
        
      if(!pos)
		sum = -sum;
      return sum; 
    } catch (exception){
        return 0;
        
    }
    }
};
