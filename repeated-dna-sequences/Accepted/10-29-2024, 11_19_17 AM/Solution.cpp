// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
        //return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
        if(s.length()<=10)
            return {};
        vector<string> rets;
        unordered_map<string, int> mp;
        for(int i=9; i<s.length(); i++) {
            string cur = s.substr(i-9, 10);
            if(mp.find(cur)!=mp.end()) { //found
                if( mp[cur] == 1 )
                    rets.push_back(cur);
            }
            mp[cur]++;
        };
        return rets;
    }
};