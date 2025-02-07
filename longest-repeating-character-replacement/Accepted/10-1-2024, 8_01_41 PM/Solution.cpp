// https://leetcode.com/problems/longest-repeating-character-replacement

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int ret = 0;
        int i=0;
        for(int j=0; j<s.size(); j++) {//check [i..j] whether it is ok.
            count[ s[j]-'A']++;
            while( j-i+1 - *max_element(count.begin(), count.end()) > k ) { //not ok
                count [s[i]-'A']--;
                i++;
            };
            ret = max(ret, j-i+1);
        }
        return ret;
    }
};