// https://leetcode.com/problems/word-pattern


class Solution {
public:
    bool wordPattern(string pattern, string str) {
		unordered_map<char, string> m;
		istringstream in(str);
		int i = 0;
		int n = pattern.size();
		for (string word; in >> word; i++) { //for all the words.
			if(i >= n) 
				break; //break?
			if(m.count(pattern[i])) {
				if( m[pattern[i]] != word )
					return false;
			} else {
				for(auto a : m) {
					if(a.second == word) 
						return false;
				}
				m[pattern[i]] = word;
			}
		}
		
		return i == n;
		
    }
};