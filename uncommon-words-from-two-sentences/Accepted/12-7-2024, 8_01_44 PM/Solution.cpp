// https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss1(s1);
        istringstream iss2(s2);
        string word;
        unordered_map<string,int> mp;
        while(iss1>>word)
            mp[word]++;
        while(iss2>>word)
            mp[word]++;
        vector<string> rets;
        for(auto item:mp) {
            if(item.second == 1)
                rets.push_back(item.first);
        }
        return rets;
    }
};