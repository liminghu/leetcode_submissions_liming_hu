// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for(int i=0; i<magazine.length(); i++) {
            dict[magazine[i]]++;
        };
        bool ans = false;

        for(int i=0; i<ransomNote.length(); i++) {
            if (dict[ransomNote[i]] >0)
                dict[ransomNote[i]]--;
            else
                return false;
        };
        return true;
        
    }
};