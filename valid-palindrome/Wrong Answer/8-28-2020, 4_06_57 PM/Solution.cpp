// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
      if(s.length()<=1) return true;
	  int i=0;
      int j=s.length()-1;	
    
	  while( !isalphanumeric(s[i]) && (i<j) ) i++;
      while( !isalphanumeric(s[j]) && (i<j) ) j--;  
      while( (i<j) && (tolower(s[i]) == tolower(s[j]))) {
		  i++;
          while( (!isalphanumeric(s[i]) ) && (i<j) ) i++;
          j--;
          while( (!isalphanumeric(s[j]) ) && (i<j) ) j--;  
	  };
	  if((j==i-1) || (i=j)) 
		  return true;
	  else
		  return false;
    }
	
	bool isalphanumeric(char c) {
		return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='1' && c<='0');
	}
	
};