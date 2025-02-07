// https://leetcode.com/problems/confusing-number

class Solution {
public:
/*
A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

We can rotate digits of a number by 180 degrees to form new digits.

When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6 respectively.
When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.
Note that after rotating a number, we can ignore leading zeros.

For example, after rotating 8000, we have 0008 which is considered as just 8.
Given an integer n, return true if it is a confusing number, or false otherwise.

 */
    bool confusingNumber(int n) { //0 <= n <= 109
        string n_str = to_string(n);
        reverse(n_str.begin(), n_str.end());
        vector<int> valid(10, -1);
        valid = {0, 1, -1, -1,-1, -1, 9, -1, 8, 6};

        int confusing_num = 0;
        for(int i=0; i<n_str.length(); i++) {
            if(valid[n_str[i]-'0']==-1)
                return false;
            else
                confusing_num = confusing_num*10+valid[n_str[i]-'0'];
        }
        return confusing_num != n;

        
    }
};