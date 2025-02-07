// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

/*Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
If the current number is even, you have to divide it by 2.
If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.
*/
class Solution {
public:
    int numSteps(string s) {
        /*  1 <= s.length <= 500
            s consists of characters '0' or '1'
            s[0] == '1'
        */
        //long long num = stoi(s, 0, 2); //base = 2;
        int res = 0;
        int n = s.length();
        while( !(s[n-1]=='1' && n==1)) { //even
            if(s[n-1] == '0') {
                s.pop_back();
                n = n-1;
                res++;
            } else { //odd
                int c = 1;
                for(int i=n-1; i>=0; i--) {
                    if(s[i] == '1') {
                        if( c == 1) {
                            s[i] = '0';
                            c = 1;
                        }; 
                    } else { //'0'
                        if( c == 1) {
                            s[i] = '1';
                            c = 0;
                        };  
                    };
                }; //end for.
                if(c == 1) {
                    s.insert(s.begin(), '1');
                    n++;
                }
                res++;
            };
        }

        return res;

        
    }
};