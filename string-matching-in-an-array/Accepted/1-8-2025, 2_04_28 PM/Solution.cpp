// https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> ans;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int k = words[j].find(words[i]);
                int m = words[i].find(words[j]);
                if(k>=0)
                    ans.insert(words[i]);
                if(m>=0)
                    ans.insert(words[j]);
                
            }
        }
        vector<string> ans_v(ans.begin(), ans.end());
        return ans_v;
    }
};