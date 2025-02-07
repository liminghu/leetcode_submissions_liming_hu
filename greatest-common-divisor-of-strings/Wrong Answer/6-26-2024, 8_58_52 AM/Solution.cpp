// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
/*
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation 
equals target. If the task is impossible, return -1.
*/
    string gcdOfStrings(string str1, string str2) { //str1 and str2 consist of English uppercase letters.
    //we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
        string ans = "";
        int sz1 = str1.length();
        int sz2 = str2.length();
        vector<int> dict(26,0);

        //The greatest common divisor must be a prefix of each string, so we can try all prefixes.
        int i=0, j=0;
        string gcd = "";
        while( i < sz1 && j < sz2 ) {
            if(str1[i] == str2[j]) {
                gcd += str1[i];
                i++;
                j++;
            } else {
                break;
            };
        };

        if( gcd.length() == 0 )
            return gcd;
        
        if( i == sz1 && j == sz2 )
            return gcd;
        
        if( i < sz1 && j == sz2 ) {
            j = 0;
            str2 = gcd;
        };

        if( i == sz1 && j < sz2 ) {
            i = 0;
            str1 = gcd;
        };


        while( i < sz1 && j < sz2 ) {
            if( str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {
                break;
            };
        };

        return ans;
    }
};