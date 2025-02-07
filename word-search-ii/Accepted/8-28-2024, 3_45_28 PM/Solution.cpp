// https://leetcode.com/problems/word-search-ii

/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
*/
class Solution {
    class trieNode {
        public:
            trieNode* children[26];
            bool isWord;
            trieNode() {
                for(int i=0; i<26; i++) 
                    children[i] = NULL;
                isWord = false;
            }
    };
public:
    trieNode* root;
    int m,n;
    bool visited[12][12];
    unordered_set<string> rets;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*  
            m == board.length
            n == board[i].length
            1 <= m, n <= 12
            board[i][j] is a lowercase English letter.
            1 <= words.length <= 3 * 104
            1 <= words[i].length <= 10
            words[i] consists of lowercase English letters.
            All the strings of words are unique.
        */
        root = new trieNode();
        for(auto word: words) {
            trieNode* node = root;
            for(auto ch:word) {
                if( node->children[ch-'a'] == NULL ) 
                    node->children[ch-'a'] = new trieNode();
                node = node->children[ch-'a'];
            }
            node->isWord = true;
        }

        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                trieNode* node = root;
                string word;
                visited[i][j] = 1;
                dfs(board, i,j, node, word);
                visited[i][j] = 0;
            }
        } 
        vector<string> ans(rets.begin(), rets.end());
        return ans;
    }

    vector<pair<int,int>> dirs{{1, 0}, {-1, 0},{0, 1},{0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j, trieNode* node, string& word) {
        //cout << "board[i][j]= " << board[i][j] << endl; 
        if( node->children[ board[i][j] - 'a' ] == NULL ) 
            return;
        node = node->children[ board[i][j] - 'a' ];
        
        word.push_back(board[i][j]);
        
        if( node->isWord )
            rets.insert(word);
        
        for(int k=0; k<4; k++) {
            int x = i + dirs[k].first;
            int y = j + dirs[k].second;
            
            if(x<0 || y<0 || x>=m || y>=n)
                continue;
            if( visited[x][y] == 1 )
                continue;

            visited[x][y] = 1;
            dfs(board, x, y, node, word);
            visited[x][y] = 0;
        }

        word.pop_back();
    }
};