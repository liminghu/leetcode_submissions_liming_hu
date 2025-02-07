// https://leetcode.com/problems/decode-string

/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square 
brackets are well-formed, etc. Furthermore, you may assume that the original data does not 
contain any digits and that digits are only for those repeat numbers, k. For example, there 
will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string current;
        int k = 0;
        for( auto ch : s ) {
            if(isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if( ch == '[') {
                countStack.push(k); //push the number k to countStack;
                stringStack.push(current); //push the current string to stringStack.
                current = ""; //reset the current str.
                k = 0; //reset count.
            } else if ( ch == ']' ) {
                string decodedString = stringStack.top();
                stringStack.pop();
                for(int k=countStack.top(); k>0; k--) { //decode k[current]
                    decodedString += current;
                }
                countStack.pop();
                current = decodedString;
            } else {
                current = current + ch;
            }
        }
        return current;
            
 /*       int index = 0;
        return decodeString(s, index);
    }
    string decodeString(const string& s, int& index) {
        string result;
        while(index <s.length() && s[index]!= ']') {
            if(!isdigit(s[index])) {
                result += s[index];
                index++;
            } else {
                int k=0;
                while(index<s.length() && isdigit(s[index])) {
                    k = k*10 + s[index]-'0';
                    index++;
                }
                index++; //ignore opening square bracket '['
                string decodedString = decodeString(s, index);
                index++; //ignore the closing bracket ']';
                while(k>0) {
                    result += decodedString;
                    k--;
                }
            }
        }
        return result;*/
    }

};