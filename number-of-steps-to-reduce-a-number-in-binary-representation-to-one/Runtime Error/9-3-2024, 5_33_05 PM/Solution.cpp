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
        int num = stoi(s, 0, 2); //base = 2;
        int res = 0;
        while(num!=1) {
            if(num%2 == 0) {
                num = num/2;
                res++;
            } else {
                num = num+1;
                res++;
            };
        }

        return res;

        
    }
};