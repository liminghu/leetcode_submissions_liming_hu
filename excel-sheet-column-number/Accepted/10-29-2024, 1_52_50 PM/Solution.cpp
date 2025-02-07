// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ret = 0;
        for(int i=0; i<n; i++) {
            ret = ret * 26;
            int c = columnTitle[i]-'A'+1; //char
            ret += c;
           // cout << "ret*26 + c: " << ret << " c: "<< c << endl;
        }
        return ret;
    }
};