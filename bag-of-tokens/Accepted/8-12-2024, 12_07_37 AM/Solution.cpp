// https://leetcode.com/problems/bag-of-tokens

/*You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        /*  0 <= tokens.length <= 1000
            0 <= tokens[i], power < 104
        */

        //face_up to get a score, and lose power.

        sort(tokens.begin(), tokens.end());
        int i=0, j= tokens.size()-1;
        int score = 0;
        int ret = 0;
        while(i<=j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                ret = max(ret, score);
                i++;
            } else if(score > 0){
                score--;
                power+=tokens[j];
                j--;
            } else 
                break;
        }
        return ret;
    }
};