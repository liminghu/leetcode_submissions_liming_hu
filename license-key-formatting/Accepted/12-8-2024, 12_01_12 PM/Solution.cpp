// https://leetcode.com/problems/license-key-formatting

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        string ret = "";
        int count = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]!='-') {
                ret.push_back(toupper(s[i]));
                count++;
                if(count == k) {
                    ret.push_back('-');
                    count = 0;
                }
            }
        }
        if(ret.size() > 0 && ret.back() == '-')
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};