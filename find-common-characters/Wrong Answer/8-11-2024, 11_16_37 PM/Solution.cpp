// https://leetcode.com/problems/find-common-characters

/*
Given a string array words, return an array of all characters that 
show up in all strings within the words (including duplicates). 
You may return the answer in any order.
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*  1 <= words.length <= 100
            1 <= words[i].length <= 100
            words[i] consists of lowercase English letters.
        */
        vector<int> count(26, 0);
        for(int i=0; i<words.size(); i++) {
            string wordi = words[i];
            for(int j=0; j<wordi.length(); j++) {
                count[wordi[j]-'a']++;
            }
        }
        vector<string> res;
        for(int i=0; i<26; i++) {
            for(int j=0; j<count[i] / words.size(); j++){
                string s;
                s.push_back(i+'a'); 
                res.push_back(s);
            }
        }
        return res;
        
    }
};