// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    int pathNum = 0;
        vector<string> ans={};
        string path = "";
        vector<string> digit_map = {"", "", "abc", "def", "dhi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) { //0 <= digits.length <= 4

        int sz = digits.length();

        if(sz==0)
            return ans;
        
        pathNum =0;
        backtrack(digits, pathNum);
        return ans;

    }

    void backtrack(string digits, int pathNum) {
        if(pathNum == digits.length()) {
            ans.push_back(path);
            return;
        }

        string letters = digit_map[digits[pathNum]-'0'];
        for(int i=0; i<letters.length(); i++) {
            path.push_back(letters[i]);
            backtrack(digits, pathNum+1);
            path.pop_back();
        }
    };
};