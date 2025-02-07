// https://leetcode.com/problems/separate-black-and-white-balls

class Solution {
public:
    long long minimumSteps(string s) {
        //0-indexed binary string s of length n, where 1 and 0 represent black and white balls
        long long swap = 0;
        int black = 0; //num of blacks.
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0') //white: need to swap to right.
                swap += (long long)black;
            else
                black++;
        }
        return swap;
    }
};