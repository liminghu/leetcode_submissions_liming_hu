// https://leetcode.com/problems/most-common-word

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> count;
        for(auto &c : paragraph) {
            c = isalpha(c)? tolower(c): ' ';
        };
        istringstream iss(paragraph);
        unordered_set<string> ban(banned.begin(), banned.end());
        string word;
        string ret="";
        int freq = 0;
        while(iss>>word) {
            if(ban.find(word)==ban.end()) { //not in banned.
                count[word]++;
                if(count[word] > freq) {
                    freq = count[word];
                    ret = word; 
                };
            }
        }
        return ret;
    }
};