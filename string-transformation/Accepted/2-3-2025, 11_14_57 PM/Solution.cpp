// https://leetcode.com/problems/string-transformation

class Solution {
    int M = 1e9+7;
public:
/*You are given two strings s and t of equal length n. You can perform the following operation on the string s:
        Remove a suffix of s of length l where 0 < l < n and append it at the start of s.
        For example, let s = 'abcd' then in one operation you can remove the suffix 'cd' and append it in front of s making s = 'cdab'.
        You are also given an integer k. Return the number of ways in which s can be transformed into t in exactly k operations.
        Since the answer can be large, return it modulo 109 + 7.
        */
    int numberOfWays(string s, string t, long long k) {//2 <= s.length <= 5 * 105
        int n= s.length();
        string ss = s+s;
        auto found1 = ss.find(t);
        if(found1 == string::npos)
            return 0;
        long long base = power_mod(n-1, k);
        int diff = k%2==0?1:-1;
        base =(base-diff)*power_mod(n, M-2)%M;
        auto found2 = ss.find(t, found1+1);
        if(found2==string::npos)
            return base;
        else if(found2-found1 == n) {
            return (base+diff)%M;
        } else {
            int d = found2-found1;
            int ans_diff =found1==0? diff:0;
            return (n/d*base+ans_diff)%M;
        };
        return 0;
    }
    long long power_mod(long long a, long long b) {
        if(b<2) {
            if(b==1)
                return a%M;
            return 1;
        };
        long long temp = power_mod(a, b/2);
        if(b%2==0)
            return temp*temp%M;
        else
            return temp*temp%M * a %M;
    }
};