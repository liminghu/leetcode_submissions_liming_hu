// https://leetcode.com/problems/integer-to-roman

class Solution {
/*
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman 
numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, 
subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 
5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 
500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.
*/
public:
    string intToRoman(int num) { //1 <= num <= 3999
        /*
        I	1
        V	5
        X	10
        L	50
        C	100
        D	500
        M	1000
        */
        unordered_map<int, char> romanDict;
        romanDict[1] = 'I';
        romanDict[5] = 'V';
        romanDict[10] = 'X';
        romanDict[50] = 'L';
        romanDict[100] = 'C';
        romanDict[500] = 'D';
        romanDict[1000] = 'M';

        string res;
        if(num >= 1000) {
            int num_m = num /1000;
            num = num % 1000; //0~999
            while( num_m > 0 ) {
                res.push_back(romanDict[1000]);
                num_m--;
            }
        };
        
        //1~1000: 500~899, 900~999,  400~499, 100~399, 1~99
        if(num >= 900) { //900~999,
            num = num - 900; //0~99
            res.push_back(romanDict[100]);
            res.push_back(romanDict[1000]);
        } else if(num >= 500) {  //500~899
            num = num - 500;  //0~399
            int num_c = num /100;
            res.push_back(romanDict[500]);
             while( num_c > 0 ) {
                res.push_back(romanDict[100]);
                num = num - 100;
                num_c--;
            }
        } else if( num >= 400 ) { //400~499
            num = num - 400; //0~99
            res.push_back(romanDict[100]);
            res.push_back(romanDict[500]);
        } 
        // num: 0~399
        //1~39,40~49, 50~99, 100~399
        if( num >= 100 ) { //100~399
            int num_c = num /100;
            num = num % 100; //0~99
             while( num_c > 0 ) {
                res.push_back(romanDict[100]);
                num_c--;
            }
        }

        //1~39,40~49, 50~89, 90~99, 
        if (num >= 90) {
            num = num - 90; //0~9
            res.push_back(romanDict[10]);
            res.push_back(romanDict[100]); 
        } else if(num >= 50 ) { //50~89
            num = num - 50;  //0~39
            int num_x = num / 10;
            res.push_back(romanDict[50]);
             while( num_x > 0 ) {
                res.push_back(romanDict[10]);
                num = num -10;
                num_x--;
            }
        } else if(num >= 40 ) { //40~49
            num = num - 40; //0~9
            res.push_back(romanDict[10]);
            res.push_back(romanDict[50]);
        }
        
        //1~39: 0~9 10~39
        if(num>=10) { //10~39
            int num_x = num /10;
            num = num % 10; //0~9
             while( num_x > 0 ) {
                res.push_back(romanDict[10]);
                num_x--;
            }
        }
        //0~9: 1~3, 4, 5~9
        if(num==9) {
            num = num - 9; //0
            res.push_back(romanDict[1]);
            res.push_back(romanDict[10]);     
        } else if(num>=5) {
            num = num - 5;  //0~3
            int num_i = num;
            res.push_back(romanDict[5]);
             while( num_i > 0 ) {
                res.push_back(romanDict[1]);
                num_i--;
            }           
        } else if(num==4) {
             num = num - 4; //0
            res.push_back(romanDict[1]);
            res.push_back(romanDict[5]);           
        } else if(num >=1) {
            while( num > 0 ) {
                res.push_back(romanDict[1]);
                num--;
            }           
        }

        return res;
        
    }
};