// https://leetcode.com/problems/minimum-window-substring

/*Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length() || s.empty() || t.empty())
            return "";
        unordered_map<char, int> mp_t; //key: char in t, count.
        for(int i=0; i<t.length(); i++) {
            mp_t[ t[i] ]++;
        };
        //int required = mp_t.size();

        unordered_map<char, int> mp_swin;
        int start = 0;

        int count = 0;
        string res = "";
        for(int i=0; i<s.length(); i++) {
            if( mp_t.find(s[i]) != mp_t.end() ) { //s[i] in t.
                mp_swin[ s[i] ]++;
                if(mp_t[ s[i] ] >= mp_swin[ s[i] ] ) //find a qualified char.
                    count++;
            };
            if(count == t.length() )  { //find a Solution
                while( mp_t.find(s[start]) == mp_t.end() || mp_t.find(s[start]) != mp_t.end() && mp_t[ s[start] ] < mp_swin[ s[start]] ) { //move start to make it better.
                    if( mp_t.find(s[start]) != mp_t.end() && mp_t[ s[start] ] < mp_swin[ s[start]] )
                        mp_swin[ s[start] ]--;
                    start++;
                };
                if(res == "" || i-start+1 <res.length()) { //find a better solution.
                    res = s.substr(start, i-start+1);
                }                
            };
        }
        return res;
    }
};