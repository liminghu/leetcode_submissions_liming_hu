// https://leetcode.com/problems/word-squares

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) { //1 <= words[i].length <= 4
        unordered_map<string, unordered_set<string>> prefixMap; //prefix->set of words that has it as the prefix.
        for(auto word: words)
            add(word, prefixMap);
        vector<vector<string>> ans;
        int len = words[0].length();
        vector<string> cur(len, string(len, ' '));
        dfs(words, prefixMap, ans, cur, 0);
        return ans;
    };
    void add(string word, unordered_map<string, unordered_set<string>>& prefixMap) {
        int n = word.length();
        string curWord(n, ' ');
        prefixMap[curWord].insert(word);
        for(int i=0; i<n; i++) {
            curWord[i] = word[i];
            prefixMap[curWord].insert(word); 
        }
    }
    void dfs(vector<string>& words, unordered_map<string, unordered_set<string>>& prefixMap, vector<vector<string>>& ans, vector<string>& cur, int i) {
        if(i==cur.size()) {
            ans.push_back(cur);
            return;
        }
        for(auto& word: prefixMap[cur[i]]) {
            string ori = cur[i];
            cur[i] = word;
            bool ok = true;
            for(int j=i+1; j<cur.size() && ok; j++) {
                cur[j][i] = word[j];
                if(!prefixMap.count(cur[j]))
                    ok = false;
            }
            if(ok)
                dfs(words, prefixMap, ans, cur, i+1);
            for(int j=i+1; j<cur.size(); j++)
                cur[j][i] = ' ';
            cur[i] = ori;
        }
    }
};