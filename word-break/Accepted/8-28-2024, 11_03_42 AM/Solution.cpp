// https://leetcode.com/problems/word-break

class Solution {
    class TrieNode {
        public:
            TrieNode* child[26];
            bool isEnd;
            TrieNode() {
                for(int i=0; i<26; i++) 
                    child[i] = NULL;
                isEnd = false;
            }
    };
    TrieNode* root;
    int memo[300];
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for(auto word: wordDict) {
            TrieNode* node = root;
            for(auto ch: word) {
                if(node->child[ch-'a'] == NULL) 
                   node->child[ch-'a'] = new TrieNode(); 
                node = node->child[ch-'a'];
            }
            node->isEnd = true;
        }
        return dfs(s, 0);

    
    /*    unordered_map<string, bool> dict;
        for(int i=0; i<wordDict.size(); i++) {
            dict[wordDict[i]] = true;
        };

        int sz = s.length();
        vector<int> dp_wb_str_i(sz+1, 0); //until index i, the word can be break.
        dp_wb_str_i[0] = 1; //init.
        
        for(int i=1; i<=sz; i++ ) {            //str until i, at least one char.
            //break point: suppose after the break point, it is one word. 
            for(int b=0; b<i; b++) {
                string sub = s.substr(b, i-b);
                if( dict.find(sub) != dict.end() )  {//found
                    dp_wb_str_i[i] = max(dp_wb_str_i[i], dp_wb_str_i[b]);  //bottom up. 
                }
            }
        }

        return dp_wb_str_i[sz]==1; */
        
    }

    bool dfs(string& s, int cur) {
        if(cur == s.size())
            return true;

        if(memo[cur] == 1)
            return false;

        TrieNode* node = root;
        for(int i=cur; i<s.size(); i++) {
            if(node->child[ s[i]-'a' ]  != NULL) {
                node = node->child[ s[i]-'a' ];
                if(node->isEnd && dfs(s,i+1))
                    return true;
            } else
                break;
        }
        memo[cur] = 1;
        return false;
    }
};