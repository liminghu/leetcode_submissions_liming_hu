// https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap

/*
Given a string s containing only digits, return the 
lexicographically smallest string
 that can be obtained after swapping adjacent digits in s with the same parity at most once.

Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
*/
class Solution {
public:
    string getSmallestString(string s) {
        int sz = s.length();
       // double ans = stod(s);
        string  res_s = s;
        int diff_max = 0;
        for(int i=0; i<sz-1; i++) {
            if((s[i]+s[i+1]) % 2 == 0 ) {
                string new_s = s;
                new_s[i] = s[i+1];
                new_s[i+1] = s[i];
                int diff = s[i] - s[i+1];
               //double new_ans = stod(new_s);
                if( diff > 0 ) {
                     diff_max = diff;
                     return new_s; 
                };
            }
        }
        return res_s;
    }
};