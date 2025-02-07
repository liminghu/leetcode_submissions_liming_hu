// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
		if( num <= 0 ) 
			return false;
        int i=0;
        double res = 0;
		while(res < num) {
          i++;	
          res=i*i;
		};
        return (res==num);
    }
};