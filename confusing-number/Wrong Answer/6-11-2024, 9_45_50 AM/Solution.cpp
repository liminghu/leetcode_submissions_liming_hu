// https://leetcode.com/problems/confusing-number

#include <stdlib.h>
class Solution {
public:
    bool confusingNumber(int n) { //0 <= n <= 109
        int ans = 0;
        string n_str;
        n_str=to_string(n);
        reverse(n_str.begin(), n_str.end());
        vector<int> confused_digit = {0,1,-1,-1, -1,-1, 9, -1, 8, 6};
        for(int i=0; i<n_str.length(); i++) {
            if(confused_digit[n_str[i]-'0'] !=-1) {
                ans+=ans*10+confused_digit[n_str[i]-'0'];
            } else {
                return false;
            }
        };
        
        if(ans==n)
            return false;
        else
            return true;
        
    }
};