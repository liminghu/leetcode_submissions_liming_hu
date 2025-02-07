// https://leetcode.com/problems/parsing-a-boolean-expression

class Solution {
public:
    bool parseBoolExpr(string expression) {//expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
        int idx = 0;
        return evaluate(expression, idx);
    }
    bool evaluate(string& expr, int& idx) {
        char cur = expr[idx];
        idx++;
        if(cur == 't')
            return true;
        if(cur == 'f')
            return false;
        if(cur == '!') {
            idx++; //skip '('
            bool res = !evaluate(expr, idx);
            idx++; //skip ')'
            return res;
        }
        // Handle AND '&(...)' and OR '|(...)'
        vector<bool> values;
        idx++; //skip '('
        while(expr[idx]!=')') {
            if(expr[idx]!=',') {
                values.push_back(evaluate(expr, idx));
            } else 
                idx++; //skip ','
        }
        idx++; //skip ')'
        if(cur == '&') {
            for(bool v: values) {
                if(!v)
                    return false;
            }
            return true;
        }
        if(cur == '|') {
            for(bool v: values) {
                if(v)
                    return true;
            }
            return false;
        }
        return false; //should not get here.
    }
};