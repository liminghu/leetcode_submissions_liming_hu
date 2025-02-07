// https://leetcode.com/problems/minimize-xor

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        /*x has the same number of set bits as num2, and
            The value x XOR num1 is minimal.
            Note that XOR is the bitwise XOR operation.
        */
        int setbits2 = 0;
        while(num2>0) {
            if(num2&1)
                setbits2++;
            num2 =(num2>>1);
        };
        int x = num1;
        int setbits1 = 0;
        while(x>0) {
            if(x&1)
                setbits1++;
            x =(x>>1);
        };
        x = num1;
        for(int i=0; i<32; i++) {
            if(setbits1>setbits2 && ( (1<<i) & num1 ) > 0) {   //num1 corresponding bit is 0.
                x ^= (1<<i); //num1 corresponding bit is 0.
                setbits1--;
            }
            //If setbits1 == setbits2, we can pick x = num1 and x XOR num1 = 0 is minimal.
           if(setbits1<setbits2 && ( (1<<i) & num1 ) == 0) { //num1 corresponding bit is 1.
                x ^= (1<<i); //num1 corresponding bit is 1.
                setbits1++;
            }            
        }
        return x; //setbits1==setbits2

    }
};