// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t 
(i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/
    string gcdOfStrings(string str1, string str2) { //1 <= str1.length, str2.length <= 1000
        int sz1 = str1.length();
        int sz2 = str2.length(); //shorter

        if( sz2 > sz1 )  
            return gcdOfStrings(str2, str1);
        
        for( int i = sz2; i > 0; i-- ) {
            int prefixLen = i;
            if(sz2 % prefixLen != 0)
                continue;
            string prefix = str2.substr(0, i);
            if( dividesString(str1, prefix) && dividesString(str2, prefix) )
                return prefix;
        }

        return "";
    }

    bool dividesString(string str, string prefix) { //non empty, sz1 >= sz2.
        int sz1 = str.length();
        int sz2 = prefix.length();
        if( sz1 % sz2 != 0 )
            return false; 
        for(int i=0; i<sz1; i++) {
            if( str[i] != prefix[ i % sz2 ] )
                return false;
        }
        return true;
    }
};