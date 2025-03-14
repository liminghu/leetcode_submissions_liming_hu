// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {

      if(x <= -(pow(2,31))) return 0;
	  if (x > int((pow(2, 31))-1)) return 0;
        
	  bool pos = true;
	  	 
	  int rem = 0;
	  int sum = 0;
	  
      while( x != 0) {
		rem = x % 10;
		x = x / 10;  
        if(sum>INT_MAX/10) return 0;
        if(sum==INT_MAX/10 && rem>7) return 0;
        if(sum<INT_MIN/10) return 0;
        if(sum==INT_MIN/10 && rem<-8) return 0;        
		sum = sum * 10;
		sum += rem;
	  };
        
      return sum; 
    }
};
