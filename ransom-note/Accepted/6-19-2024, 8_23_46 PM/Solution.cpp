// https://leetcode.com/problems/ransom-note

class Solution {
public:
    /*
    Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
    */
    bool canConstruct(string ransomNote, string magazine) { //ransomNote and magazine consist of lowercase English letters.
        bool ans = false;
        unordered_map<char, int> dict;
        for(int i=0; i<magazine.length(); i++) {
            dict[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.length(); i++) {
            if(dict.find(ransomNote[i])!=dict.end() && dict[ransomNote[i]] >0)
                dict[ransomNote[i]]--;
            else
                return false;
        };
        
        return true;
        
    }
};