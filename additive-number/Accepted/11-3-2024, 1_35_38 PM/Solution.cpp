// https://leetcode.com/problems/additive-number

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if( num.length() <= 2 )
            return false;
        int n = num.length();
        for(int i=1; i<=n/2; i++) { //i:the length of the first number
            for(int j=1; j<=(n-i)/2; j++) {//j: the length of the second number.
                if( check( num, i, j ) )
                    return true;
            }
        };
        return false;
    }
    bool check(string num, int i, int j) {
        if( i>1 && num[0] == '0') //no leading '0'
            return false;
        if( j>1 && num[i] == '0')
            return false;    
        long long sum = (long long)0;
        string sum_str = "0"; 
        int sum_len = 0;
        long long  x = stol(num.substr(0, i));
        long long  y = stol(num.substr(i, j));
        for(int start = i + j; start < num.length(); start += sum_str.length() ) {
            sum = x + y;
            sum_str = to_string(sum);
            sum_len = sum_str.length();
            if( start + sum_len > num.length() || start + sum_len <= num.length() &&  sum_str != num.substr(start, sum_len) )
                return false;
            x = y;
            y = sum;
        }
        return true;
    }
};