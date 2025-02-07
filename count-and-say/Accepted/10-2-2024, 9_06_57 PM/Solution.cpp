// https://leetcode.com/problems/count-and-say

/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters 
(repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). 
For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" 
with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
Constraints:
1 <= n <= 30
 Follow up: Could you solve it iteratively?
*/
class Solution {
public:
    string countAndSay(int n) {
        string say = "1";
        for(int i = 1; i<n; i++) {  //bottom up.
            string new_say = "";
            char start = say[0];
            int count = 0;
            for(int j=0; j<say.length(); j++) { //say the old string.
                char c = say[j];
                if(c == start)
                    count++;  //1
                else {
                    new_say += to_string(count) + start;
                    count = 1; //reset count.
                    start = say[j];
                }
            }
            //cout << "count: " << count << " start: " << start<< endl;
            //cout << "count string: " << to_string(count) << " start string: " << to_string(start)<< endl;
            new_say += to_string(count) + start;
            //cout << "new_say: " << new_say << endl;
            say = new_say;
        }
        return say;
    }
};