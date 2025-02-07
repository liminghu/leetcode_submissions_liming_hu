// https://leetcode.com/problems/minimum-length-of-string-after-operations

class Solution {
public:
    int minimumLength(string s) {
        vector<int> index(26, 0);
        for(int i=0; i<s.length(); i++) {
            index[s[i]-'a']++;
        };
        int ret = 0;
        for(int i=0; i<26; i++) {
            int sz = index[i];
            if(sz>=3)
                ret += sz%2==1? 1:2;
            else
                ret += sz;
        };
        return ret;
    }
};