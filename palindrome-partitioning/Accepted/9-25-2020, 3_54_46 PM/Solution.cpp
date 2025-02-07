// https://leetcode.com/problems/palindrome-partitioning

//DFS+ backtracking
class Solution {
public:
  vector<vector<string>> partition(string s) {
	  int n = s.length();
	  vector<vector<string>> ans;
	  vector<string> cur;
	  function<void(int)> dfs = [&](int start) {
		if(start == n) {
			ans.push_back(cur);
			return;
		}
		
		for(int i=start; i<n; i++) {
			if(!isPalindrome(s, start, i)) continue;
			cur.push_back(s.substr(start, i-start+1));
			dfs(i+1);
			cur.pop_back();
		}
	  };
	  dfs(0);
	  return ans;
   } 
   
   bool isPalindrome(const string& s, int l, int r) {
	while(l < r)
		if(s[l++] != s[r--] ) return false;
	return true;
  }
};