// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        while(right<n) {
            while(right < n && s[right] != ' ')
                right++;
            if(s[right]==' ' || right==n) {
                reverse(s, left, right-1);
                while(s[right]==' ' && right<n)
                    right++;
                left = right;
            };
        }
        return s;
    }
    void reverse(string&s, int left, int right) {
        while(left<right) {
            swap(s[left], s[right]);
            left++;
            right--;
        };
    }    
};