// https://leetcode.com/problems/reverse-words-in-a-string-ii

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int start = 0;
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ' ) {
               reverseWord(s, start, i-1); 
                start = i+1;            
            }
        };
        reverseWord(s, start, s.size()-1);
    }
    void reverseWord(vector<char>& s, int i, int j) {
        while(i<j) {
            swap(s[i], s[j]);
            i++;
            j--;
        };
    }
};