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
    unordered_map<int, vector<int>> mp;  //int: left bound. vector<int>: right bound. sorted from left to right.

    int longestValidSubstring(string word, vector<string>& forbidden) {
        /*  1 <= word.length <= 105
            word consists only of lowercase English letters.
            1 <= forbidden.length <= 105
            1 <= forbidden[i].length <= 10
            forbidden[i] consists only of lowercase English letters.
            */

            //encode all the forbidden strings.
            for(auto& s: forbidden) {
                LL code = 0;
                for(auto ch:s) { //1 <= forbidden[i].length <= 10
                    code = (code << 5) + (ch -'a') + 1; //must start from 1, otherwise we can not tell 'aaa' from 'a'.
                }
                st.insert(code);                
            }

            //sliding window.
            for(int len = 1; len<=10; len++)
                slide(word, len);

            int w_sz = word.length();
            int rightBound = w_sz;
            int ret = 0;
            for(int i=w_sz-1; i>=0; i--) {  //from right to left.
                if(mp.find(i) != mp.end()) { //i as the left bound.
                    for(int j: mp[i]) //j as the right bound.
                        rightBound = min(rightBound, j);
                }
                ret = max(ret, rightBound-i); //j-i
            }
            return ret;
    }

    void slide(string word, int len) { //brute force: len: 1~10.
        int sz = word.length();
        LL code = 0;
        //check all the sliding window start from i for window size: len.
        for(int i=0; i<sz; i++) {
            if( i >= len ) //just keep the code length until len-1.
                code = code & ( ( 1ll << ( 5*(len-1) ) ) - 1 );    
            code = (code << 5) + word[i] - 'a' + 1; //final code length len, until i.

            if( i >= len-1 && st.find(code) != st.end() ) //only when i>=len-1, we can have len forbidden string.  
                mp[ i- len + 1 ].push_back( i );  //[i-len+1, i], length: len.
        }
    }
};