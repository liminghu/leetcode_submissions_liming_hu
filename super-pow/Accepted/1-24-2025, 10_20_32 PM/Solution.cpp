// https://leetcode.com/problems/super-pow

class Solution {
    int M = 1337;
public:
    int superPow(int a, vector<int>& b) {//ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
        if(b.empty())
            return 1;
        int last = b.back();
        b.pop_back();
        int prev = superPow(a, b);
        return powmod(prev, 10) * powmod(a, last) %M;
    }
    int powmod(int a, int k) {
        a%=M;
        int res = 1;
        for(int i=0; i<k; i++)
            res = (res*a)%M;
        return res;
    }
};