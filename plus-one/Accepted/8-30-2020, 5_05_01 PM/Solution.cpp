// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       for(int i = digits.size() - 1; i >= 0; i--) {
			if(digits[i] != 9) {
				digits[i] = digits[i] +1;
			    return digits;
			} else {
				digits[i] = 0;
			}
	   };
	   vector<int> res(digits.size()+1, 0);
	   res[0] =1;
	   return res;
    }
};