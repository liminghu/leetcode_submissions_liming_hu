// https://leetcode.com/problems/design-search-autocomplete-system

struct Trie {
    unordered_map<char, Trie*> nodes;
    int cnt = 0;
    bool isWord = false;
    void build(string str, int times) {
        auto cur_node = this;
        for(auto c: str) {
            if(cur_node->nodes[c] == NULL)
                cur_node->nodes[c] = new Trie();
            cur_node = cur_node->nodes[c];
        }
        //cur_node is at the leaf:
        cur_node->isWord = true;
        cur_node->cnt -= times; //will be sorted from smaller...
    }
    vector<string> search(string str, int top) {
        auto cur_node = this;
        int i = 0;
        while(i < str.size() && cur_node->nodes[ str[i] ] )
            cur_node = cur_node->nodes[str[i++]];
        if( i < str.size() ) //not found
            return {};
        vector<pair<int, string>> res;
        cur_node->helper(str, res);
        sort(res.begin(), res.end());
        vector<string> ans;
        for(int i=0; i<min((int)res.size(), top); i++)
            ans.push_back(res[i].second);
        return ans;
    }
    void helper(string str, vector<pair<int, string>> & res) {
        auto cur_node = this;
        if(cur_node->isWord)
            res.push_back( {cur_node->cnt, str} ); 
        for(auto it: cur_node->nodes)   //unordered_map<char, Trie*> nodes;
            it.second->helper(str + it.first, res);
    }
};
class AutocompleteSystem {
public:
    Trie trie;
    string newStr;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0; i<sentences.size(); i++) 
            trie.build(sentences[i], times[i]);
    }
    vector<string> input(char c) {
        if(c == '#') {
            trie.build(newStr, 1);
            newStr = "";
            return {};
        }
        newStr += c;
        return trie.search(newStr, 3);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */