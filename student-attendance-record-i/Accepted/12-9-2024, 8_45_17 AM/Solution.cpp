// https://leetcode.com/problems/student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int a = 0;
        int late3 = false;

        for(int i=0; i<n; i++) {
            if(s[i]=='A') {
                a++;
                if(a>=2)
                    return false;
            }
            if(i>=2 && s[i]=='L' && s[i-1]=='L' && s[i-2]=='L')
                return false;
        }
        return true;
    }
};