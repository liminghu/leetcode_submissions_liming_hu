// https://leetcode.com/problems/group-anagrams

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*1 <= strs.length <= 104
            0 <= strs[i].length <= 100
            strs[i] consists of lowercase English letters.*/
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++) {
            string cur_s = strs[i];
            sort(cur_s.begin(), cur_s.end());
            mp[cur_s].push_back(strs[i]);
        }

       for(auto i:mp) {
        res.push_back(i.second);
       }
        return res;

    }

 
};