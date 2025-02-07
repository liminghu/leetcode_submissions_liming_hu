// https://leetcode.com/problems/sentence-similarity-ii

class UnionFindSet {
public:
    bool Union(const string& word1, const string& word2) {
        const string& p1 = Find(word1, true);
        const string& p2 = Find(word2, true);
        if (p1 == p2) return false;        
        parents_[p1] = p2;
        return true;
    }
    
    const string& Find(const string& word, bool create = false) {
        if (!parents_.count(word)) {
            if (!create) return word;
            return parents_[word] = word;
        }
        
        string w = word;
        while (w != parents_[w]) {
            parents_[w] = parents_[parents_[w]];
            w = parents_[w];
        }
        
        return parents_[w];
    }
private:
    unordered_map<string, string> parents_;
};
 
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& similarPairs) {
        if (words1.size() != words2.size()) return false;
        
        UnionFindSet s;
        for (const auto& pair : similarPairs)
            s.Union(pair[0], pair[1]);
        
        for (int i = 0; i < words1.size(); ++i) 
            if (s.Find(words1[i]) != s.Find(words2[i])) return false;
        
        return true;        
    }
};

