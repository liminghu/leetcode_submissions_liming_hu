// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while(columnNumber > 0) {
            columnNumber--;
            char c = columnNumber % 26;
            cout << "c: " << char('A'+c) << endl;
            columnNumber = columnNumber / 26;
            ret.push_back('A'+c);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};