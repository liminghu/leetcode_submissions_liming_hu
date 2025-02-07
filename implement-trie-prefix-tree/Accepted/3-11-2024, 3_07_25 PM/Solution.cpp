// https://leetcode.com/problems/implement-trie-prefix-tree

#define N 26

struct Node {
    Node *links[N];
    bool isWord = false;

    bool containKey(char ch) {
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch-'a'] = node;
    }

    Node *get(char ch) {
        return links[ch-'a']; 
    }

    void setEnd() {
        isWord = true;
    }

    bool isEnd() {
        return isWord;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        };
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
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