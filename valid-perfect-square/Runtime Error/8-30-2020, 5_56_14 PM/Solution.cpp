// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
		if( num <= 0 ) 
			return false;
        int i=0;
        
		while(i*i < num) {
          i++;			
		}	
		return (i*i==num);
    }
};