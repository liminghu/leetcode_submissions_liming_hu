// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        stack<int> t;  //previous sign just before the '('
        t.push(1);  //for all the signs those are not in the parentheses
        int sum=0, temp=0, lastSign=1;
        for(auto c: s)
        {
            if(c=='(') t.push(lastSign); //save the sign just before the '('
            else if(c==')') t.pop();
            
            if(c>='0' && c<='9'){  
                temp=temp*10+c-'0';
            }
            
            if(c=='-'||c=='+'){
                sum+=lastSign*temp; //calculate the number before current sign
                temp=0;
                lastSign=(c=='-'?-1:1)*t.top();  //deal with the stack influencing sign
            }
        }
        sum+=lastSign*temp; //calculate the last number
        return sum;
    }
};