// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
      int count =0;
      bool isLastEnd = false;
      for (int i=s.length()-1; i>=0; i--) {
	    if ((s[i] >='a' && s[i]<='z') || (s[i] >='A' && s[i]<='Z')) {
		  isLastEnd = true;
	      count++;
        } else {
		 if(isLastEnd == true)
			 return count;
		}
	  }
	  return count; 
    }
};