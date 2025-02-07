// https://leetcode.com/problems/group-anagrams

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
class Solution {
public:
   bool isAnagram(string s, string t) {
        if(s == t)
            return true;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s==t)
            return true;
        else
            return false;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*1 <= strs.length <= 104
            0 <= strs[i].length <= 100
            strs[i] consists of lowercase English letters.*/
        vector<bool> saved(strs.size(), 0);
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++) {
            if(saved[i] == 1)
                continue;
            
            res.push_back({strs[i]});
            saved[i] = 1;
            for(int j=1; j<strs.size(); j++) {    
                if(saved[j] == 1)
                    continue;
                if(isAnagram(strs[i], strs[j]) ) {
                    res[res.size()-1].push_back(strs[j]);
                    saved[j] = 1;
                } 
            };
        }
        return res;

    }

 
};