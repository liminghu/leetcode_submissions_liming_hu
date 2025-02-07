// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int n1_digit; 
        int n2_digit;
        int s_digit;
        int c = 0;

        //make sure num1 length < num2 length
        if(num1.length() > num2.length()) {
            string temp;
            temp = num1;
            num1 = num2;
            num2 = temp;
        } ;

        int short_size = num1.length();


        int ans_i=0;
        for(int i=short_size-1; i>=0; i--) {
            n1_digit = num1[i] - '0';
            n2_digit = num2[i+ num2.length()-num1.length()] - '0';
            s_digit = c + n1_digit + n2_digit;
            if(s_digit>=10) {
                s_digit -= 10;
                c = 1;
            } else {
                c = 0;
            };
            ans.push_back( '0'+ s_digit);
        };

        string rest;
        rest = num2.substr(0, num2.length()-num1.length());

         for(int i=rest.length()-1; i>=0; i--) {
            s_digit = rest[i]-'0' +c;
            if(s_digit>=10) {
                s_digit -= 10;
                c = 1;
            } else {
                c = 0;
            };
            ans.push_back( '0' + s_digit);
         };

        char carry = '1';
         if(c==1)
            ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};