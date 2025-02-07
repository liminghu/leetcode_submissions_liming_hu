// https://leetcode.com/problems/shortest-word-distance-ii

class WordDistance {
private:
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++)
            mp[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> idx1Set = mp[word1]; 
        vector<int> idx2Set = mp[word2];
        int min_dist = INT_MAX;
        for(int i=0; i<idx1Set.size(); i++) {
            for(int j=0; j<idx2Set.size(); j++) {
                min_dist = min(min_dist, abs(idx1Set[i]- idx2Set[j]));
            }
        } 
        return min_dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */