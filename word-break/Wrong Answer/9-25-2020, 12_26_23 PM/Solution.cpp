// https://leetcode.com/problems/word-break

//DP: 记忆化递归。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		//create a hashset of words for fast query.
		unordered_set<string> dict(wordDict.cbegin(), wordDict.cend()); //cbegin: const iterator.
		
		return wordBreak(s, dict);
   }
   
   bool wordBreak(const string& s, const unordered_set<string>& dict) {
		//in memory, directly return.
		if(mem_.count(s)) return mem_[s];
		if(dict.count(s)) { //whole string is a word, memorize it and return.
			mem_[s] = true;
			return true;
		};
		
		//try every break point.
		for(int j=1; j < s.length(); j++) {
			const string left = s.substr(0, j);
			const string right = s.substr(j);
			//find the solution for s.
			if(dict.count(right) && wordBreak(left, dict) )
				mem_[s] = true;
			    return true;
		};
		
		//no solution for s, memorize it and return.
		mem_[s] = false;
		return false;
   }
private:
	unordered_map<string, bool> mem_;
};