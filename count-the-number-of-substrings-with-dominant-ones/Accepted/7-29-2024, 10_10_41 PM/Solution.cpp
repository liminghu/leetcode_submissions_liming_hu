// https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones

class Solution {
public:
    int numberOfSubstrings(string s) {
        /*
        You are given a binary string s.
        Return the number of 
        substrings
        with dominant ones.
        A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
        */

        /*1 <= s.length <= 4 * 104
            s consists only of characters '0' and '1'.
        */
        int sz = s.length();
        vector<int> numZeros(sz+1, 0);
        vector<int> numOnes(sz+1, 0);
        for(int i=0; i<sz; i++) {
            if(s[i] == '0') {
                numZeros[i+1] =  numZeros[i] + 1;
                numOnes[i+1] = numOnes[i];
            } else {
                numOnes[i+1] =  numOnes[i] + 1;
                numZeros[i+1] = numZeros[i];               
            };
        }

        int start = 0;
        int end = sz -1;

        int ans = 0;
        for(int i=0; i<sz; i++) {
            for(int j=i; j<sz; j++) {
                int numZeroij = numZeros[j+1] - numZeros[i];
                int numOneij = numOnes[j+1] - numOnes[i];
                if( numOneij >= numZeroij * numZeroij ) {
                    ans++;
                    int k = sqrt(numOneij);

                    if(k > numZeroij) 
                        ans += ( j + ( k - numZeroij ) >= sz? ( sz - j - 1 ): ( k - numZeroij ) );
                    j += (k-numZeroij);                   
                } else {
                    j += ( numZeroij*numZeroij -numOneij - 1 );
                }
            } 
        }
        return ans;
    }
};