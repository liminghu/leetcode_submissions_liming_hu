// https://leetcode.com/problems/strobogrammatic-number-ii

/*
Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Example 1:
Input: n = 2
Output: ["11","69","88","96"]

Example 2:
Input: n = 1
Output: ["0","1","8"]
 
Constraints:
1 <= n <= 14
*/
class Solution {
public:
    unordered_map<char, char> mp;
    vector<string> findStrobogrammatic(int n) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['9'] = '6';
        mp['8'] = '8';
        return generateStroboNumbers(n, n);
    }
    vector<string> generateStroboNumbers(int n, int finalLength) {
        vector<string> res;
        if( n == 0 )
            return { "" };
        if( n == 1 )
            return { "0", "1", "8" };
        vector<string> prevStroboNums = generateStroboNumbers(n-2, finalLength);
        vector<string> curStrobeNums;
        for(string& prevStroboNum: prevStroboNums) {
            for(auto item: mp) {
                if(! (item.first == '0' && n == finalLength) ) { // ||
                    //except when the current reversible pair is '00' and n == finalLength 
                    //(because we can't append '0' at the beginning of a number) and push this new number in ans. 
                    curStrobeNums.push_back(item.first + prevStroboNum + item.second);
                }
            }
        }
        return curStrobeNums;
    }
};