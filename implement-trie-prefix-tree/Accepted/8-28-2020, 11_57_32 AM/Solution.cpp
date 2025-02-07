// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root_(new TrieNode) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		TrieNode* p = root_.get();
		for(const char c: word) {
			if(!p->children[c-'a'])
				p->children[c-'a'] = new TrieNode();
			p = p->children[c-'a'];
		}
		p->is_word = true; //the last letter, set is_word true.
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode* p=find(word);
        return (p != nullptr) &&(p->is_word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
	
private:
    struct TrieNode {
	  bool is_word;
	  vector<TrieNode *> children;
	  TrieNode(): is_word(false), children(26, nullptr) {}
	  ~TrieNode() {
	    for(TrieNode* child: children)
			if(child) delete child;
	  }
	};
	unique_ptr<TrieNode> root_;
	const TrieNode* find(const string& prefix) {
		const TrieNode* p = root_.get();
		for (const char c: prefix) { //follw the prefix string to the trie leaf.
			p = p->children[c-'a'];
			if(p==nullptr) break;
		}
		return p;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
 