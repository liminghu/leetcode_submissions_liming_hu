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
        vector<int> CommonCount(26, 0);

        for(char& ch :words[0]) {
            CommonCount[ch-'a']++;
        }

        for(int i=1; i<words.size(); i++) {
            string wordi = words[i];
            vector<int> currentCount(26,0);
            for(int j=0; j<wordi.length(); j++) {
                currentCount[(wordi[j]-'a')]++;
            }

            for(int letter=0; letter<26; letter++) {
                CommonCount[letter] = min(CommonCount[letter], currentCount[letter]);
            }

        }
        vector<string> res;
        for(int i=0; i<26; i++) {
            for(int j=0; j<CommonCount[i]; j++){
                string s;
                s.push_back(i+'a'); 
                res.push_back(s);
            }
        }
        return res;
        
    }
};