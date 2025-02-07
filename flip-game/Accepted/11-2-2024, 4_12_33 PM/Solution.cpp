// https://leetcode.com/problems/flip-game

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> rets;
        for(int i=0; i<currentState.size()-1; i++) {
            string temp = currentState;
            if(currentState[i] == '+' && currentState[i+1]=='+') {
                temp[i] = '-';
                temp[i+1] = '-';
                rets.push_back(temp);
            };
        }
        return rets;
    }
};