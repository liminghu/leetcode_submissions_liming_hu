// https://leetcode.com/problems/permutation-sequence

/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Constraints:
1 <= n <= 9
1 <= k <= n!
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits(n,0);
        for(int i=1; i<=n; i++)
            digits[i-1] = i;
        
        vector<int> fact(n+1,1); //fact[0] will not be used.
        for(int i=2; i<=n; i++)
            fact[i] = i * fact[i-1];
                
        string ret = "";
        k--; //0 indexed.
        while( n>0 ) {
            int a = k / fact[n-1];   //maximum n-1.  k: 0 indexed. 
            ret.push_back('0'+ digits[a]);
            k -=  a * fact[n-1];
            n--;
            digits.erase(digits.begin()+a); // a was used.
        }
        return ret;
    }
};