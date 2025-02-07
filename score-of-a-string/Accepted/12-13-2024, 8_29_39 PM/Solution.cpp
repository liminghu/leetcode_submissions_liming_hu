// https://leetcode.com/problems/score-of-a-string

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i=0; i<s.length()-1; i++) {
            int score_i = abs(s[i]-s[i+1]);
            score += score_i; 
        }
        return score;
    }
};