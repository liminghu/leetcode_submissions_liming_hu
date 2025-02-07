// https://leetcode.com/problems/length-of-the-longest-valid-substring

/*You are given a string word and an array of strings forbidden.
A string is called valid if none of its substrings are present in forbidden.
Return the length of the longest valid substring of the string word.
A substring is a contiguous sequence of characters in a string, possibly empty.
*/
using LL = long long;
class Solution {
public:
    unordered_set<LL> st;
    unordered_map<int, vector<int>> mp;

    int longestValidSubstring(string word, vector<string>& forbidden) {
        /*  1 <= word.length <= 105
            word consists only of lowercase English letters.
            1 <= forbidden.length <= 105
            1 <= forbidden[i].length <= 10
            forbidden[i] consists only of lowercase English letters.
            */

            for(auto& s: forbidden) {
                LL code = 0;
                for(auto ch:s) {
                    code = (code << 5) + (ch -'a')+1;
                }
                st.insert(code);                
            }

            for(int len = 1; len<=10; len++)
                slide(word, len);

            int w_sz = word.length();
            int rightBound = w_sz;
            int ret = 0;
            for(int i=w_sz-1; i>=0; i--) {
                if(mp.find(i) != mp.end()) {
                    for(int j: mp[i])
                        rightBound = min(rightBound, j);
                }
                ret = max(ret, rightBound-i);
            }
            return ret;
    }

    void slide(string word, int len) {
        int n = word.length();
        LL code = 0;
        for(int i=0; i<n; i++) {
            if(i>=len)
                code = code & ((1ll << (5*(len-1)))-1);
            code = (code << 5) + word[i]-'a'+1;

            if(i>=len-1 && st.find(code)!=st.end())
                mp[i-len+1].push_back(i);
        }
    }
};