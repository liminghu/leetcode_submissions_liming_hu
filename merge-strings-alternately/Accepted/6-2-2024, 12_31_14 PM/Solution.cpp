// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i=1, j=0;
        ans.push_back(word1[0]);

        while(i<word1.length() || j<word2.length()) {
            if(j<word2.length()) {
                ans+=word2[j];
                j++;
            }
            if(i<word1.length()) {
                ans+=word1[i];
                i++;
            }
        };
        return ans;
        
    }
};