// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        string ret = "";
        bool neg = false;
        if(num==0)
            return "0";
        if(num<0) {
            neg = true;
            num = -num;
        };
        while(num) {
            ret.push_back('0'+num%7);
            num = num/7;
        };
        if(neg)
            ret.push_back('-');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};