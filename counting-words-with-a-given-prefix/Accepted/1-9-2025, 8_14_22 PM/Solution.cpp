// https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        //Return the number of strings in words that contain pref as a prefix.
        int ret = 0;
        for(int i=0; i<words.size(); i++) {
            if(words[i].find(pref)==0)
                ret++;
        }
        return ret;
    }
};