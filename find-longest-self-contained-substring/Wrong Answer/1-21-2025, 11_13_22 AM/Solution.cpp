// https://leetcode.com/problems/find-longest-self-contained-substring

class Solution {
public:
    int maxSubstringLength(string s) {
        int n = s.length();
        int ret = -1;
        vector<int> totalCount(26);
        for(char c:s)
            totalCount[c-'a']++;
        for(int i=1; i<=26; i++) { //i is the number of unique chars in the sub
            int valid = 0, unique = 0, left = 0;
            vector<int> count(26, 0);
            for(int right=0; right<n; right++) {
                count[s[right]-'a']++; // Add the char to the sub
                if(count[s[right]-'a'] == 1)// we saw a new char
                    unique++;
                if(count[s[right]-'a'] == totalCount[s[right]-'a']) // all of this char is in this sub
                    valid++;
                for(; unique>i; left++) {
                    count[s[left]-'a']--; 
                    if(count[s[left]-'a'] == 0)
                        unique--;
                    if(count[s[left]-'a'] == totalCount[s[left]-'a']) // all of this char is in this sub
                        valid--;
                }
                if(valid==i && right-left+1!=n)
                    ret = max(ret, right-left+1);
            }
        }
        return ret;
    }
};