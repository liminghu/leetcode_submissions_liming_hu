// https://leetcode.com/problems/strobogrammatic-number

/*
Given a string num which represents an integer, return true if num is a strobogrammatic number.
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 Example 1:
Input: num = "69"
Output: true

Example 2:
Input: num = "88"
Output: true

Example 3:
Input: num = "962"
Output: false
 
Constraints:
1 <= num.length <= 50
num consists of only digits.
num does not contain any leading zeros except for zero itself.
*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        string rotated_num;
        for(int i=num.length()-1; i>=0; i--) {
            if(num[i] == '0' || num[i] == '1' || num[i] == '8')
                rotated_num.push_back(num[i]);
            else if(num[i] == '6')
                rotated_num.push_back('9');
            else if(num[i] == '9')
                rotated_num.push_back('6');
            else
                return false;
        }
        return rotated_num == num;
    }
};