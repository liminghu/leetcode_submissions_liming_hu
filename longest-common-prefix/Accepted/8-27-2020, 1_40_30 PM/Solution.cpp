// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      //divide and conquer.
		if (strs.size() == 0)
			return "";
		else {
			int s = strs.size();
			return plongestCommonPrefix(strs, 0, s - 1);
		}
    }
private:
	string plongestCommonPrefix(vector<string>& strs, int left, int right) {
		if (left > right)
		{
			return "";
	    }
	  if (left==right)
		  return strs[left];
	  else {
		int mid =(left+right)/2;
		string lcpLeft = plongestCommonPrefix(strs, left, mid);
		string lcpRight = plongestCommonPrefix(strs, mid+1, right);
		return commonPrefix(lcpLeft, lcpRight); 
	  }
	}
	string commonPrefix(string left, string right) {
	  int min_length = min(left.length(), right.length());
	  for (int i=0; i<min_length; i++) {
	    if(left[i]!=right[i])
			return left.substr(0, i);
	  }
	  return left.substr(0, min_length);
	}
};