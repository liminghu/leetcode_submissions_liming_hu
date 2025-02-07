// https://leetcode.com/problems/find-the-closest-palindrome

class Solution {
public:
    string nearestPalindromic(string n) { //1 <= n.length <= 18
        int len = n.size();
        int i =  len%2 == 0? len/2-1: len/2;
        long firstHalf = stol(n.substr(0, i+1));
        vector<long> possibities(5, 0);
        possibities[0] = halftoPalin(firstHalf, len%2==0);
        possibities[1] = halftoPalin(firstHalf+1, len%2==0);
        possibities[2] = halftoPalin(firstHalf-1, len%2==0);        
        possibities[3] = (long)pow(10, len-1)-1;  
        possibities[4] = (long)pow(10, len)+1;    
        long diff = LONG_MAX; 
        long res = 0;
        long nl = stol(n);
        for(long cand:possibities) {
            if(cand==nl)
                continue;
            if(abs(cand-nl)<diff) {
                diff = abs(cand-nl);
                res = cand;
            } else if(abs(cand-nl)==diff) {
                res = min(res,cand);
            }
        }    
        return to_string(res);
    }
    long halftoPalin(long left, bool even) {
        long res = left;
        if(!even) 
            left = left/10;
        while(left) {
            res = res*10 + left%10;
            left = left/10;
        }
        return res;
    }
};