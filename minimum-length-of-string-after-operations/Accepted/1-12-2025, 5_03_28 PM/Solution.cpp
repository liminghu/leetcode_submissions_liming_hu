// https://leetcode.com/problems/minimum-length-of-string-after-operations

class Solution {
public:
    int minimumLength(string s) {
        vector<vector<int>> index(26);
        for(int i=0; i<s.length(); i++) {
            index[s[i]-'a'].push_back(i);
        };
        int ret = 0;
        for(int i=0; i<26; i++) {
            int sz = index[i].size();
            if(index[i].size()>=3)
                ret += sz%2==1? 1:2;
            else
                ret += sz;
        };
        return ret;
    }
};