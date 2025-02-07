// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
       if(n < 2) return 0;
       vector<bool> primeNum(n, true);
       for(int i=2; i*i<n; i++) {
           if(primeNum[i]) {
             for(int j=i; j*i<n; j++) {
               primeNum[j*i] = false;
             };
           }
       };
        
       int countPrime =0;
       for(int i=2; i<n; i++) {
           if(primeNum[i])
               countPrime++;
       }
       
       return countPrime;
    }
};