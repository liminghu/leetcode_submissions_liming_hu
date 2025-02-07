// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create a hashset of words for fast query.
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        // Query the answer of the original string.
        return wordBreak(s, dict);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& dict) {
        // In memory, directly return.
        if(mem_.count(s)) return mem_[s];
        // Whole string is a word, memorize and return.
        if(dict.count(s)) return mem_[s]=true;
        // Try every break point.
        for(int j=1;j<s.length();j++) {
            const string left = s.substr(0,j);
            const string right = s.substr(j);
            // Find the solution for s.
            if(dict.count(right) && wordBreak(left, dict))
                return mem_[s]=true;
        }
        // No solution for s, memorize and return.
        return mem_[s]=false;
    }
private:
    unordered_map<string, bool> mem_;
};