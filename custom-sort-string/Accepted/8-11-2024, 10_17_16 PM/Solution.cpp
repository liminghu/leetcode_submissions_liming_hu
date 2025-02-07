// https://leetcode.com/problems/custom-sort-string

/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before 
a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/
class Solution {
public:
    string customSortString(string order, string s) {
        /*1 <= order.length <= 26
            1 <= s.length <= 200
            order and s consist of lowercase English letters.
            All the characters of order are unique.*/

        int order_sz = order.length();
        unordered_map<char,int> mp;
        for(int i=0; i<order.length(); i++) {
            mp[order[i]] = i; 
        }

        vector<vector<char>> bucket(order.length()+1, vector<char>(0, 0));

        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i])!=mp.end()) {
                bucket[ mp[s[i]] ].push_back(s[i]); 
            } else 
                bucket[order.length()].push_back(s[i]);
        }  

        string res = "";
        for(int i=0; i<bucket.size(); i++) {
            for(int j=0; j<bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
            }
        }

        return res;
    }
};