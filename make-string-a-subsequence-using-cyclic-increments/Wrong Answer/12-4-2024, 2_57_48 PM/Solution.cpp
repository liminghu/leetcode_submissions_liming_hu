// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int left = 0;
        int right = n-1;
        while(right-left+1 >= m) {
            if(isSubSequence(str1, str2))
                return true;
            string new_str1 = change(str1, left, right);
            if(isSubSequence(new_str1, str2))
                return true;
            left++;
        };
        return false;
    }
    string change(string str1, int left, int right) {
        for(int i=left; i<=right; i++) {
            str1[i] = str1[i]+1>'z'? 'a':str1[i]+1;
        }
        return str1;
    }
    bool isSubSequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int i = 0;
        int j = 0;
        while(i<m && j<n) {
            if(s1[i] == s2[j]) 
                j++;
            i++;
        }
        return j == n;
    } 
};