// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> words_count;
        for(string& word:words) {
            words_count[word]++;
        }

        vector<pair<int, string>> candidates;
        for(auto& p:words_count) {
            candidates.push_back({-p.second, p.first}); //count is negative.
        }
        sort(candidates.begin(), candidates.end());

        vector<string> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(candidates[i].second);
        }

        return ans;

           


    }
};