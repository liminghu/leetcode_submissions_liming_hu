// https://leetcode.com/problems/implement-trie-prefix-tree

#define N 26
struct trieNode {
    //vector<trieNode*> children; //(26, NULL);
    trieNode* children[N];

    bool isWord = false;
    bool containKeys(char ch) {
        return children[ch-'a'] != NULL;
    };
    void put(char ch, trieNode*node) {
        children[ch-'a'] = node;
    }
    trieNode *get(char ch) {
        return children[ch-'a'];
    }
    void setEnd() {
        isWord = true;
    }
    bool isEnd() {
        return isWord;
    }

};

class Trie { //word and prefix consist only of lowercase English letters
private:
    trieNode* root;
public:
    Trie() {
        root = new trieNode();
        
    }
    
    void insert(string word) {
        trieNode *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containKeys(word[i]))
                node->put(word[i], new trieNode());
            node = node->get(word[i]);
        
        }
        node->setEnd(); 
    }
    
    bool search(string word) {
        trieNode *node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containKeys(word[i])) 
                node = node->get(word[i]);
            else
                return false;
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        trieNode *node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(node->containKeys(prefix[i])) 
                node = node->get(prefix[i]);
            else
                return false;
        }
        return true;

        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */