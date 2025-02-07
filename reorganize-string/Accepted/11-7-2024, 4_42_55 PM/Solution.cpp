// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    //just need to return one string, not all of them.
    string reorganizeString(string s) { //s consists of lowercase English letters.
        int k = 2;
        unordered_map<char, int> freq;
        for(auto ch:s)
            freq[ch]++;
        priority_queue<pair<int, char>> pq; //freq, char. max
        for(auto x:freq) {
            pq.push({x.second, x.first});
        }
        string ret;
        while(!pq.empty()) {
            if(pq.size()<k && pq.top().first > 1)
                return "";
            int n = min(k, (int)pq.size());
            vector<pair<int,char>> temp;
            for(int i=0; i<n; i++) {
                ret.push_back(pq.top().second);
                temp.push_back(pq.top());
                pq.pop();
            }
            for(auto x:temp) {
                if(x.first>1)
                    pq.push({x.first-1, x.second});
            }
        }
        return ret;
    }
};