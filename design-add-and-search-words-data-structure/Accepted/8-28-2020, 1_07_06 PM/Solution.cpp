// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary():root_(new TrieNode) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root_.get();
		for(const char c: word) {
			if(!p->children[c-'a'])
				p->children[c-'a'] = new TrieNode();
			p = p->children[c-'a'];
		}
		p->is_word = true; //the last letter, set is_word true.
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
		return find(root_.get(), word, 0);
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
	const bool find(TrieNode* curr, const string& word, int idx=0) {
		if(idx==word.size()) return curr->is_word;
		if(word[idx]=='.') {
			for(int i=0; i<26; i++) {
				if(curr->children[i] && find(curr->children[i], word, idx+1))
					return true;
            }
		} else {
			if(curr->children[word[idx]-'a'] && find(curr->children[word[idx]-'a'], word, idx+1))
				return true;
		}
		return false;
	}
};