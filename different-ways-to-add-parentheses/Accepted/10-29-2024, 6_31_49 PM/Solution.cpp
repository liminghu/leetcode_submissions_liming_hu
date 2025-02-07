// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;
        if(expression.length() == 0)
            return ret;
        if(expression.length() == 1) {
            ret.push_back(stoi(expression));
            return ret;
        }
        if(expression.length()==2 && isdigit(expression[0])) {
            ret.push_back(stoi(expression));
            return ret;
        }
        for(int i=0; i<expression.length(); i++) {
            char curr = expression[i];
            if(isdigit(curr))
                continue;
            vector<int> left_ret = diffWaysToCompute(expression.substr(0, i));
            vector<int> right_ret = diffWaysToCompute(expression.substr(i+1));
            for(int leftValue: left_ret) {
                for(int rightValue: right_ret) {
                    int computeResult = 0;
                    switch(curr) {
                        case '+':
                            computeResult = leftValue + rightValue;
                            break;
                        case '-':
                            computeResult = leftValue - rightValue;
                            break;
                        case '*':
                            computeResult = leftValue * rightValue;
                            break;
                    }
                    ret.push_back(computeResult);
                }
            }
        }
        return ret;
    }
};