// https://leetcode.com/problems/find-longest-awesome-substring

class Solution {
public:
    int longestAwesome(string s) {
        constexpr int kInf = 1e9;
        vector<int> idx(1024, kInf);
        idx[0] = -1;
        int mask  = 0; //prefix's state 0: even, 1:odd.
        int ans = 0;
        for(int i = 0; i<s.length(); i++) {
          mask ^= (1 << (s[i] - '0'));
          ans = max(ans, i-idx[mask]);
          //One digit with odd count is allowed.
          for(int j=0; j<10; ++j)
              ans = max(ans, i-idx[mask ^(1<<j)]);
          idx[mask] = min(idx[mask],i);
        }
        return ans;
    }
};