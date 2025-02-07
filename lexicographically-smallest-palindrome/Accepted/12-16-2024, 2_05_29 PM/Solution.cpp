// https://leetcode.com/problems/lexicographically-smallest-palindrome

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        int left=0;
        int right=n-1;
        string ret(n, 0);;
        while(left<right) {
            if(s[left]<=s[right]) {
                ret[left]=ret[right]=s[left];
            }else if(s[left]>s[right]) {
                ret[left]=ret[right]=s[right];
            }
            left++;
            right--;
        }
        if(n%2==1)
            ret[n/2] = s[n/2];
        return ret;
    }
};