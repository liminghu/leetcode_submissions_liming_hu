// https://leetcode.com/problems/fraction-addition-and-subtraction

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;
        int i=0;
        while(i<expression.length()) {
            int curNum = 0;
            int curDenom = 0;
            bool isNegative = false;
            if(expression[i]== '-' || expression[i]=='+') {
                if(expression[i]== '-' )
                    isNegative = true;
                i++;
            };
            while(isdigit(expression[i])) {
                int val = expression[i] - '0';
                curNum += curNum*10 + val;
                i++;
            }
            if(isNegative)
                curNum *= -1;
            i++; //skip /
            while( i <expression.length() && isdigit(expression[i])) {
                int val = expression[i] - '0';
                curDenom += curDenom*10 + val;
                i++;
            }   
            num = num*curDenom + curNum*denom;
            denom = denom*curDenom;        
        }
        int gcd = abs(findGCD(num, denom));
        num /= gcd;
        denom /= gcd;
        return to_string(num)+"/"+to_string(denom);
    }
    int findGCD(int a, int b) {
        if(a==0)
            return b;
        return findGCD(b%a, a);
    }
};