// https://leetcode.com/problems/generalized-abbreviation

class Solution {

public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> rets;
        for(int state=0; state< (1<<n); state++) {
            string abbr;
            for(int i=0; i<n; i++) {
                if( (state>>i) & 1 ) {
                    int j = i;
                    while(j<n && ((state>>j) & 1) )
                        j++;
                    int len = j-i;
                    abbr+= to_string(len);
                    i=j-1;
                } else {
                    abbr.push_back(word[i]);
                }
            }
            rets.push_back(abbr);
        }
        return rets;
    }
};