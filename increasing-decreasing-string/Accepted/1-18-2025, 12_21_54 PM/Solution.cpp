// https://leetcode.com/problems/increasing-decreasing-string

class Solution {
public:
    string sortString(string s) {//1 <= s.length <= 500
        string ret;
        vector<int> count(26, 0);
        for(char c:s) 
            count[c-'a']++;
        while(ret.size() < s.size()) {
            for(int i=0; i<26; i++) {
                if(count[i]>0) {
                    ret += 'a'+i;
                    count[i]--;
                }
            };
            for(int i=25; i>=0; i--) {
                if(count[i]>0) {
                    ret += 'a'+i;
                    count[i]--;
                }
            }
        }
        return ret;
    }
};