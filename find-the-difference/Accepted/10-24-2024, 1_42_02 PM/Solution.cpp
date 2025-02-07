// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> dict(26);
        for(int i=0; i<t.length(); i++)
            dict[t[i]-'a']++;
        for(int i=0; i<s.length(); i++)
            dict[s[i]-'a']--;
        for(int i=0; i<26; i++) {
            if(dict[i]!=0)
                return 'a'+i;
        }
        return 'a';
        
    }
};