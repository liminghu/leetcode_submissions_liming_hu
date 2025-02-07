// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) { //2 <= s.length <= 500
        int n = s.length();
        vector<int> count0(n, 0);
        count0[0] = s[0]=='0'? 1:0;
        for(int i=1; i<n; i++) {
            if(s[i]=='0')
                count0[i] = count0[i-1]+1;
            else
                count0[i] = count0[i-1];
        }
        int ret = 0;
        for(int i=1; i<n; i++) {
            int left0 = count0[i-1];
            int right0 = (count0[n-1]-left0);
            int right1 = (n-i)-right0;
            ret = max(ret, left0+right1);
        }
        return ret;
        
    }
};