// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
		
		if(s.size()==0) return -1;
		for(int i=0; i<s.length(); i++) {
		 if(dict.find(s[i])==dict.end())
		   dict.insert(make_pair(s[i], 1));
		 else {
		   int v=dict[s[i]];
		   dict[s[i]] = v + 1;
		   //dict.insert(make_pair(s[i], v+1));
		 };
		};
		
		//check
		for(int i=0; i<s.length(); i++) {
		  if(dict.find(s[i])!=dict.end())
		  {
		    int v=dict[s[i]];;
			if (v==1)
				return i;
		  } else {
		    cout<<"error";
		  }
			  
		}
		return -1;
    }
};