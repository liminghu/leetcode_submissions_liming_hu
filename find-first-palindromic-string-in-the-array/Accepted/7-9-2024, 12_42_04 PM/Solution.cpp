// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution {
public:
/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            if(isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
    bool isPalindrome(string word) {
        if(word.length()<=1)
            return true;
        int start = 0;
        int end = word.length() -1;

        while(start<end) {
            if(word[start] == word[end]) {
                start++;
                end--;
            } else 
                return false;
        }

        return true;

    }
};