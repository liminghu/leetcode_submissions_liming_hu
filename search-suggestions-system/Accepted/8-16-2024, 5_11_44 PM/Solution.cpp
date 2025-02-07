// https://leetcode.com/problems/search-suggestions-system

/*
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character 
of searchWord is typed. Suggested products should have common prefix with searchWord. If there 
are more than three products with a common prefix return the three lexicographically minimums products.
Return a list of lists of the suggested products after each character of searchWord is typed.
*/
struct TrieNode {
    bool isEnd;
    TrieNode* child[26];
    TrieNode() {
        for(int i=0; i<26; i++) {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class Solution {
    TrieNode* root;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        /*  1 <= products.length <= 1000
            1 <= products[i].length <= 3000
            1 <= sum(products[i].length) <= 2 * 104
            All the strings of products are unique.
            products[i] consists of lowercase English letters.
            1 <= searchWord.length <= 1000
            searchWord consists of lowercase English letters.
        */
      
        sort(products.begin(), products.end());
        vector<vector<string>> rets;
        string pre = "";
        for(int i=0; i<searchWord.size(); i++) {
            pre.push_back(searchWord[i]);
            vector<string> ret;
            auto iter = lower_bound(products.begin(), products.end(), pre);
            for(int k=0; k<3; k++) {
                int len = pre.length();
                if(iter == products.end())
                    break;
                if(iter->substr(0, len) != pre)
                    break;
                ret.push_back(*iter);
                iter = next(iter,1);
            }
            rets.push_back(ret);
        }
        return rets;
      
    /*    root = new TrieNode();
        for(auto product: products) {
            TrieNode* node = root;
            for(char ch:product) {
                if(node->child[ch-'a'] == NULL) {
                    node->child[ch-'a'] = new TrieNode();
                }
                node = node->child[ch-'a'];
            };
            node->isEnd = true; 
        }


        vector<vector<string>> rets;
        string pre= "";
        TrieNode* node = root;
        for(int i=0; i<searchWord.size(); i++) {
            char ch = searchWord[i];
            if(node->child[ch-'a'] == NULL) {
                for(int j=i; j<searchWord.size(); j++) {
                    rets.push_back({});
                }
                break;
            }
            node = node->child[ch-'a'];
            pre.push_back(ch);

            string str;
            vector<string> ret;
            DFS(node, str, ret);

            for(int j=0; j<ret.size(); j++) {
                ret[j] = pre + ret[j];
            }
            rets.push_back(ret);
        }
        return rets;*/
    }

    void DFS(TrieNode* node, string& str, vector<string>& ret) {
        if(ret.size() == 3)
            return;
        if(node->isEnd == true)
            ret.push_back(str);
        
        for(int i=0; i<26; i++) {
            if(node->child[i] == NULL)
                continue;
            str.push_back('a'+i);
            DFS(node->child[i], str, ret);
            str.pop_back();
        }
    }
};