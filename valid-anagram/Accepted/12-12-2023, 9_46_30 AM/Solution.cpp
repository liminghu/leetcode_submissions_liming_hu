// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        unordered_map<char, int> map;
        for(size_t i=0; i<s.size(); i++)
            map[s[i]]++;
        for(size_t i=0; i<t.size(); i++) {
            map[t[i]]--;    
            if(map[t[i]] == 0)
                map.erase(t[i]);
        }
        
        if(map.size()==0) 
            return true;
        else
            return false;

    }
};