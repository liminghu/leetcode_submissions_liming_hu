// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) { //789
        vector<string> res;
        for(int i=1; i<=n; i++) {
            res.push_back(to_string(i));
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(int i=1; i<=n; i++) {
            ans.push_back(stoi(res[i-1]));
        }
        
        return ans;
    }
};