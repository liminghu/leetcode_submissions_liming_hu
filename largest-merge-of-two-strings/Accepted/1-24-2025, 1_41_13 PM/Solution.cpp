// https://leetcode.com/problems/largest-merge-of-two-strings

class Solution {
public:
    string largestMerge(string word1, string word2) {
        //Return the lexicographically largest merge you can construct.
        string ret = "";
        while(word1.length()>0 && word2.length()>0) {
            if(word1>word2) {
                ret += word1[0];
                word1.erase(0, 1);
            } else {
                ret += word2[0];
                word2.erase(0, 1);               
            }
        };
        if(word1.length()==0) 
            ret += word2;
        if(word2.length()==0)
            ret += word1;
        return ret;
    }
};