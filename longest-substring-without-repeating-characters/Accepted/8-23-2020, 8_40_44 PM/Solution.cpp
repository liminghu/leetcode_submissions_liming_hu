// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int res = 0;
		int j=0;
		for (int i=0; i<s.length(); ++i) {
			if (map.find(s[i]) != map.end()) {
				j= max(j, map[s[i]]+1);
			}
			map[s[i]]=i;
			res=max(res, i-j+1);
		}
		return res;
			
    }
};