// https://leetcode.com/problems/design-add-and-search-words-data-structure

/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.
Implement the WordDictionary class:
WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.
 */
/*1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/
class WordDictionary {

    struct TrieNode {
        public:
            bool isEnd;
            unordered_map<char, TrieNode*> children;
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto ch:word) {
            if( node->children.find(ch) == node->children.end())
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        };
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchInNode(word, root);
    }
    bool searchInNode(string word, TrieNode* node) {
        for(int i=0; i<word.length(); i++) {
            if( node->children.find(word[i]) == node->children.end()) {
                if(word[i] == '.' ) {                
                    for(auto x:node->children) {
                        TrieNode* child = x.second;
                        if(searchInNode(word.substr(i+1), child))
                            return true;
                    }
                }
                return false;
            } else 
                node = node->children[word[i]];
        };
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */