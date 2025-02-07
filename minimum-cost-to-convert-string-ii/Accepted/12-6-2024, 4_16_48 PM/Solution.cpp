// https://leetcode.com/problems/minimum-cost-to-convert-string-ii

using LL = long long;
class TrieNode {
public:
    TrieNode* next[26];
    int idx;
    TrieNode() {
        for(int i=0; i<26; i++) 
            next[i] = NULL;
        idx = -1;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i]
        for(auto& s:original)
            reverse(s.begin(), s.end());
        for(auto& s:changed)
            reverse(s.begin(), s.end()); 
        unordered_set<string> set;
        set.insert(original.begin(), original.end());
        set.insert(changed.begin(), changed.end());    
        unordered_map<string,int> mp;
        int idx = 0;
        for(string word:set) {
            mp[word] = idx;
            TrieNode* node = root;
            for(char c:word) {
                if(node->next[c-'a'] == NULL)
                   node->next[c-'a'] = new TrieNode();
                node = node->next[c-'a']; 
            }
            node->idx = idx;
            idx++;
        } 
        int n = set.size();
        vector<vector<LL>> d(n, vector<LL>(n, LLONG_MAX/2));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j)
                    d[i][j] = 0;
            }
        }
        for(int i=0; i<original.size(); i++)
            d[mp[original[i]]][mp[changed[i]]] = min(d[mp[original[i]]][mp[changed[i]]], (LL)cost[i]);
        for(int k=0; k<n; k++) { //Floyd algorithm
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) 
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);                
            }
        }    
        int m = source.size();
        source = "$" + source;
        target = "$" + target;
        vector<LL> dp(m+1);
        dp[0] = 0;
        for(int i=1; i<=m; i++) {
            dp[i] = LLONG_MAX/2;
            if(source[i]==target[i])
                dp[i] = dp[i-1];
            TrieNode* node1 = root;
            TrieNode* node2 = root;
            for(int j=i; j>=1; j--) {
                if(node1->next[source[j]-'a']==NULL)
                    break;
                if(node2->next[target[j]-'a']==NULL)
                    break;           
                node1 = node1->next[source[j]-'a'];
                node2 = node2->next[target[j]-'a'];
                int idx1 = node1->idx;  
                int idx2 = node2->idx;
                if(idx1==-1 || idx2==-1)
                    continue;
                dp[i] = min(dp[i], dp[j-1]+d[idx1][idx2]);         
            }
        }     
        if(dp[m]==LLONG_MAX/2)
            return -1;
        else
            return dp[m];
    }
};