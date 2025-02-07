// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = spaces.size();
        int n = s.length();
        string ret(n+m, ' ');
        int j = 0; //idx for the spaces.
        for(int i=0; i<n; i++) {
            if(j<m && i==spaces[j]) {
                ret[i+j] = ' ';
                j++; //move to next space.
            }
            ret[i+j] = s[i]; //add char from the original.
        }
        return ret;
    }
};