// https://leetcode.com/problems/valid-palindrome


class Solution {
public:
    bool isPalindrome(string s) {
      if(s.length()<=1) return true;
	  int i=0;
      int j=s.length()-1;	
    
	  while( !isalnum(s[i]) && (i<j) ) i++;
      while( !isalnum(s[j]) && (i<j) ) j--;
      while( (i<j) && (tolower(s[i]) == tolower(s[j]))) {
		  i++;
		  j--;
          while( !isalnum(s[i])  && (i<j) )
			  i++;

          while( !isalnum(s[j])  && (i<j) )
			  j--;  
	  };
	  if((j==i-1) || (i==j)) {
		  return true;
	  }else
		  return false;
    }
	
	//bool isalphanumeric(char c) {
	//	return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
	//}
	
};
