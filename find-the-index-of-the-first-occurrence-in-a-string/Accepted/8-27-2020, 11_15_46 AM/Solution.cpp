// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
      int h_s = haystack.length();
      int n_s = needle.length();
      if(n_s==0) return 0; 

      for(int i=0; i<=(h_s-n_s); i++) {
		if(haystack.substr(i,n_s)==needle)
			return i;
	  }
      return -1;  
	}  
};