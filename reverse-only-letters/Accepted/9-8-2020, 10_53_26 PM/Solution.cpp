// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string S) {
       int l = 0;
       int r = S.length() -1;
       string ans = S;
       while(l<r) {
	    if( !isalpha(S[l]) ) 
			l++;
		else {
			if( !isalpha(S[r]) ) 
				r--;
			else {
				char temp;
			    temp = S[l];
				ans[l] = ans[r];
				ans[r] = temp;
                l++;
                r--;
			}
		}
	   }
       return ans;	   
    };

};