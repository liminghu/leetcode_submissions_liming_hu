// https://leetcode.com/problems/count-vowel-strings-in-ranges

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<bool> vowelWord(n, false);
        for(int i=0; i<n; i++) {
            string word = words[i];
            if(isVowel(word[0]) && isVowel(word[word.length()-1]))
                vowelWord[i] = true;
        };
        vector<int> prefix(n, 0);
        prefix[0] = (vowelWord[0] == true);
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1]+(vowelWord[i] == true);
        vector<int> rets;
        for(auto& query: queries) {
            int li = query[0];
            int ri = query[1];
            int ret;
            if(li>0)
                ret = prefix[ri]-prefix[li-1];
            else
                ret = prefix[ri];
            rets.push_back(ret);
        }
        return rets;
    }
    bool  isVowel(char c) {
        if(c == 'a' || c=='e' || c=='i' || c== 'o' || c=='u')
            return true;
        else
            return false;
    }

};