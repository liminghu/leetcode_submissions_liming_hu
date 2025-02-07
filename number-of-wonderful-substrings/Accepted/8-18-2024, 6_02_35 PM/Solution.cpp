// https://leetcode.com/problems/number-of-wonderful-substrings

/*A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), 
return the number of wonderful non-empty substrings in word. If the same substring appears multiple 
times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.
*/
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        //1 <= word.length <= 105
        //word consists of lowercase English letters from 'a' to 'j'.
        int n = word.length();
        int state = 0;
        vector<int> count(1<<10);
        count[0] = 1; //no letters, valid wonderful string.
        long long ret = 0;
        for(int i=0; i<n; i++) {
            int k = word[i] - 'a';
            state = state ^ (1<<k); // state[i], state is even.

            ret += count[state]; //all letter freqs are even.
            count[state] += 1;  //state[i]
            for(int k = 0; k<10; k++) { //state is even.
                int stateJ = state ^(1<<k);   //stateJ
                ret += count[stateJ];
            }
           
        }
        return ret;
    }
};

