// https://leetcode.com/problems/defuse-the-bomb

/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        /*
            n == code.length
            1 <= n <= 100
            1 <= code[i] <= 100
            -(n - 1) <= k <= n - 1
        */
        int sz = code.size();
        vector<int> res(sz, 0);

        if (k == 0)
            return res;

        long sum_k = 0;        
        if(k > 0) { //k <= n - 1
            for(int i=1; i<=k; i++) {
                sum_k += code[i];
            };
            for(int i=0; i<sz; i++) {
                res[i] = sum_k;
                sum_k += code[(k+i+1) % sz ] - code[ (i+1)%sz ];
            }
        } else { //k negative, k> = -(n - 1) 
            k = -k;
            for(int i=1; i<=k; i++) {
                sum_k += code[ (sz-i) % sz ];
            };
            for(int i=0; i<sz; i++) {
                res[i] = sum_k;
                sum_k += code[i] - code[ (i-k+sz)%sz];
            }
        }

        return res;
        
    }
};