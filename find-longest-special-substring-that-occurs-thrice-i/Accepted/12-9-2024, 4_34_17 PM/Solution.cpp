// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> count;
        int subLength = 0;
        for(int start=0; start<s.length(); start++) {
            char c = s[start];
            subLength = 0;
            for(int end=start; end<s.length(); end++) {
                if(c==s[end]) {
                    subLength++;
                    count[{c, subLength}]++;
                } else
                    break;
            };
        }
        int ans = 0;
        for(auto item:count) {
            int len = item.first.second;
            if(item.second>=3 && len >ans)
                ans = len;
        }
        if(ans==0)
            return -1;
        return ans;
    }
};