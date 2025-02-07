// https://leetcode.com/problems/strange-printer

class Solution {
    vector<vector<int>> t_;
public:
    int strangePrinter(string s) {
        int n = s.length();
        t_ = vector<vector<int>>(n, vector<int>(n, 0));
        return turn(s, 0, n-1); 
    }
    int turn(const string& s, int i, int j) {
        if(i>j)
            return 0;
        if(t_[i][j]>0)
            return t_[i][j];
        int ans = turn(s, i, j-1) + 1;
        for(int k=i; k<j; k++) {
            if(s[k]==s[j])
                ans = min(ans, turn(s, i, k)+turn(s, k+1, j-1));
        };
        return t_[i][j] = ans;
    }
};