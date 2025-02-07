// https://leetcode.com/problems/word-subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //Return an array of all the universal strings in words1. You may return the answer in any order.
        vector<int> count(26), tmp(26);
        int i=0;
        for(string s2: words2) {
            tmp = counter(s2);
            for(int i=0; i<26; i++)
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> res;
        for(string s1:words1) {
            tmp = counter(s1);
            for(i=0; i<26; i++) {
                if(tmp[i]<count[i])
                    break;
            }
            if(i==26)
                res.push_back(s1);
        }
        return res;
    }
    vector<int> counter(string s1) {
        vector<int> dict1(26, 0);
        for(char c: s1)
            dict1[c-'a']++;
        return dict1;
    }
};