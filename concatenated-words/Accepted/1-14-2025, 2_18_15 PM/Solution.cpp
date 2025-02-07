// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> rets;
        unordered_set<string> set;
        for(string word:words)
            set.insert(word);
        for(string word:words) {
            set.erase(word);
            if(canBreak(word, set))
                rets.push_back(word);
            set.insert(word);
        }
        return rets;
    }
    bool canBreak(string& word, unordered_set<string>& set) {
        if(set.size()==0)
            return false;
        int n = word.size();
        if(n==0) return false;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(!dp[j])
                    continue;
                if( set.count( word.substr(j, i-j) ) ) {
                    dp[i] = true;
                    break;
                };
            }
        } 
        return dp[n];
    }
};