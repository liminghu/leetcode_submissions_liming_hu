// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        if(n==0)
            return 0;
        int minChange = 0;
        for(int i=0; i<n; i+=2) {
            if(s[i]!=s[i+1])
                minChange++;
        }
        return minChange;
    }
};