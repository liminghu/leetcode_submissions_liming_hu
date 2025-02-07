// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, INT_MAX);
        int prev = INT_MIN/2; //prev of the last character C we've seen
        for(int i=0; i<n; i++) {
            if(s[i]==c) {
                prev = i;
            };
            res[i] = i-prev;
        }
        prev = INT_MAX/2;
        for(int i=n-1; i>=0; i--) {
            if(s[i]==c) {
                prev = i;
            };
            res[i] = min(res[i], prev-i);            
        }
        return res;
    }
};