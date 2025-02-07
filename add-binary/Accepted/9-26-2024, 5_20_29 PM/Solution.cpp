// https://leetcode.com/problems/add-binary

//Given two binary strings a and b, return their sum as a binary string.
/*
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int m = a.length();
        int n = b.length();
        int carry = 0;
        for(int i=0; i<min(m,n); i++) {
            int a_i = a[m-1-i]-'0';
            int b_i = b[n-1-i]-'0';
            int res_i = 0;
            cout << a[m-i]-'0' << " " << b[n-i]-'0' << endl;
            res_i = (a_i + b_i + carry);
            if(res_i < 2) { //0, 1
                carry = 0;
            } else if(res_i >= 2){
                res_i = res_i -2;
                carry = 1;
            };
            ans.push_back(res_i+'0');
        };

        if(m>n) {
            for(int i=n; i<m; i++) {
               int a_i = a[m-1-i]-'0';
               int res_i = 0;
               res_i = (a_i + carry);
               if(res_i < 2) { //0, 1
                    carry = 0;
               } else if(res_i >= 2){
                    res_i = res_i - 2;
                    carry = 1;
               };
               ans.push_back(res_i+'0');
            }
        } else if(m<n) {
            for(int i=m; i<n; i++) {
               int b_i = b[n-1-i]-'0';
               int res_i = 0;
               res_i = (b_i + carry);
               if(res_i < 2) { //0, 1
                    carry = 0;
               } else if(res_i >= 2){
                    res_i = res_i - 2;
                    carry = 1;
               };
               ans.push_back(res_i+'0');
            }
        }
        if(carry==1) {
            ans.push_back('1');
        }
      
        reverse(ans.begin(), ans.end());
        return ans;
    }
};