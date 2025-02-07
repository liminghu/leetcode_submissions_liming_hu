// https://leetcode.com/problems/word-break-ii

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence
 where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
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
    int memo[301];
    vector<string> rets;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        /*  1 <= s.length <= 20
            1 <= wordDict.length <= 1000
            1 <= wordDict[i].length <= 10
            s and wordDict[i] consist of only lowercase English letters.
            All the strings of wordDict are unique.
            Input is generated in a way that the length of the answer doesn't exceed 105.
        */
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
        vector<string> words;
        dfs(s, 0, words);
        return rets;
    }
   bool dfs(string& s, int cur, vector<string>& words) {
        if(memo[cur] == 1)
            return false;

        if(cur == s.size()) {
            string temp;
            for(auto word: words) 
                temp += word + " ";
            temp.pop_back(); //remove last " "
            rets.push_back(temp);
            return true;
        }

        TrieNode* node = root;
        bool flag = false;
        for(int i=cur; i<s.size(); i++) {
            if(node->child[ s[i]-'a' ]  != NULL) {
                node = node->child[ s[i]-'a' ];
                if(node->isEnd) {
                    
                    words.push_back( s.substr(cur, i-cur+1) ); //found.
                    
                    if( dfs(s, i+1, words) )
                        flag = true;

                    words.pop_back(); //back track
                }
            } else
                break;
        }
        if( flag == false )
            memo[cur] = 1;
        return flag;
    }
};