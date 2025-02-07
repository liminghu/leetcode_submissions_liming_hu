// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> ans = {};
    vector<string> path = {};
    vector<vector<string>> partition(string s) { //1 <= s.length <= 16; s contains only lowercase English letters.
        backtrack(s,0);  //0: start location.
        return ans;
    }

    void backtrack(string s,int start) {
        if(start>=s.length()) {
            ans.push_back(path);
            return;
        };

        for(int i=start; i<s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                string pal_str = s.substr(start, i+1-start);
                path.push_back(pal_str);  
            } else 
                continue;
            backtrack(s, i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(string s, int start, int end) {
        if(end < start)
            return false;
        if(start==end)
            return true;

        while(start<end) {
            if(s[start]==s[end]) {
                start++;
                end--;
            } else
                return false;
        }
        return true;
    }
};