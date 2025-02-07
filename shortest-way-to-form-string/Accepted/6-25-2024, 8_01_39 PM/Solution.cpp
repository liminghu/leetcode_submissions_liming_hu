// https://leetcode.com/problems/shortest-way-to-form-string

class Solution {
public:
/*
A subsequence of a string is a new string that is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their 
concatenation equals target. If the task is impossible, return -1.
*/
    int shortestWay(string source, string target) {
         //1 <= source.length, target.length <= 1000
        //source and target consist of lowercase English letters.
        int sz1 = source.length();
        int sz2 = target.length();
        //look for maximum subsequence
        int i = 0;
        int begin = 0; 
        int j = 0;
        int count = 0;
        
        while( j < sz2 ) {
            j = begin;
            while( i < sz1 ) {
                if(source[i] == target[j]) 
                    j++;
                i++;
            }

            if(j == begin)
                return -1;
            else
                count++;

            i = 0;
            begin = j;
        }
        return count;       
    }
};