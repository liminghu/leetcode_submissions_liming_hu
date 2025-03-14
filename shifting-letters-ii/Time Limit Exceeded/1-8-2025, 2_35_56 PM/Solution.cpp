// https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //shifts[i] = [starti, endi, directioni].
        //forward if directioni = 1, or shift the characters backward if directioni = 0.
        int n = shifts.size();
        string ret = s;
        for(int i=0; i<n; i++) {
            int starti = shifts[i][0];
            int endi = shifts[i][1];
            int directioni = shifts[i][2];
            for(int j = starti; j<=endi; j++) {
                if(directioni==1) {
                    ret[j] = ret[j]=='z'?'a': ret[j]+1;
                } else {
                    ret[j] = ret[j]=='a'?'z': ret[j]-1;
                }
            }
        }
        return ret;
    }
};