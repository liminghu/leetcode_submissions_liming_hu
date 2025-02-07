// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int left = 0;
        int right = n-1;
        while(right-left+1 >= m) {
            int found = str1.find(str2);
            if (found!=std::string::npos)
                return true;
            string new_str1 = change(str1, left, right);
            found = new_str1.find(str2);
            if (found!=std::string::npos)
                return true;
            left++;
        };
        return false;
    }
    string change(string& str1, int left, int right) {
        for(int i=left; i<=right; i++) {
            str1[i] = str1[i]+1>'z'? 'a':str1[i]+1;
        }
        return str1;
    }
};