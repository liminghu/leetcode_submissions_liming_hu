// https://leetcode.com/problems/generate-parentheses


class Solution {
public:
    vector<string> generateParenthesis(int n) {
		//Solution: DFS
		//Time complexity: O(2^n)
		//Space complexity: O(k + n)   
/*		vector<string> ans;
		string cur;
		if (n > 0) 
			dfs(n, n, cur, ans);
		return ans;*/
		
		//https://leetcode.com/problems/generate-parentheses/discuss/817715/Easy-OptimizedConcise-and-Faster-Than-100.00-of-C%2B%2B-Submissions
		vector<string> v;
		ok(v, "", 0, 0, n);
		return v;
		
    }

private:	
	void ok(vector<string> &v, string cur, int open, int close, int max) {
	
		if(cur.size() == max*2) {//we got the complete combination.
			v.push_back(cur);
			return;
		}
		
		if(open < max) ok(v, cur+'(', open+1, close, max); //add opening.
		if(close < open) ok(v, cur+')', open, close+1, max); //add opening.
	}
/*private:
	void dfs(int l, int r, string& s, vector<string>& ans) {
		if(l==0 && r == 0) {
			ans.push_back(s);
			return;
		};
		if(r<l) return;
		if(l>0) {
			s += "(";
			dfs(l-1,r, s, ans);
			s.pop_back();
		}
		if(r>0) {
			s+=")";
			dfs(l, r-1, s, ans);
			s.pop_back();
		};
	}*/
	
};

