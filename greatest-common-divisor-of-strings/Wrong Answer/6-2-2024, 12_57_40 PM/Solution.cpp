// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) { //str1 and str2 consist of English uppercase letters.
    //we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
        string ans;
        int n1 = str1.length(), n2=str2.length();
        vector<int> dict(26,0);

        //The greatest common divisor must be a prefix of each string, so we can try all prefixes.
        int i=0, j=0;
        string gcd;
        while(i<n1 & j<n2) {
            if(str1[i]== str2[j]) {
                gcd+=str1[i];
                i++;
                j++;
            } else {
                break;
            };
        };

        if(gcd.length()==0)
            return gcd;
        
        if(i==n1 && j==n2)
            return gcd;
        
        if(i<n1 && j==n2) {
            j=0;
            str2 = gcd;
        };

        if(i==n1 && j<n2) {
            i=0;
            str1 = gcd;
        };


        while(i<n1 & j<n2) {
            if(str1[i]== str2[j]) {
                ans+=str1[i];
                i++;
                j++;
            } else {
                break;
            };
        };

        return ans;
    }
};