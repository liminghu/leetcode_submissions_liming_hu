// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression

class Solution {
public:
    string minimizeResult(string expression) {//3 <= expression.length <= 10
        int n = expression.length();
        int ret = INT_MAX;
        int l = 0;  
        int r = n-1;
        int posPlus = expression.find('+');
        int minL = 0;
        int minR = 0;
        for(l=0; l<posPlus; l++) {
            for(r=posPlus+1; r <n; r++) {
                string leftStr = expression.substr(0, l);
                int leftN = 1;
                int rightN = 1;
                if(leftStr.length()==0)
                    leftN = 1;
                else
                    leftN = stoi(leftStr);    
                string rightStr = expression.substr(r+1, n-1-r);
                if(rightStr.length()==0)
                    rightN = 1;
                else
                    rightN = stoi(rightStr);
                string firstStr = expression.substr(l, posPlus-l);
                string secondStr = expression.substr(posPlus+1, r-posPlus);
                int cur = leftN*(stoi(firstStr)+stoi(secondStr))*rightN;
                if(cur < ret) {
                    ret = cur;
                    minL = l;
                    minR = r;
                }
            }
        };
        return expression.substr(0, minL)+ "(" + expression.substr(minL, minR-minL+1) + ")" + expression.substr(minR+1);
    }
};