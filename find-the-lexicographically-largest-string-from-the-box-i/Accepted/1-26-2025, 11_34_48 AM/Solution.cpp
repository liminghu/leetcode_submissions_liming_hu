// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i

class Solution {
public:
    string answerString(string word, int numFriends) {//1 <= word.length <= 5 * 10^3
        if(numFriends ==1)
            return word;
        int n = word.size();
        int maxLength = n-numFriends+1;
        string res = "";
        for(int i=0; i<n; i++) {
            res = max(res, word.substr(i, maxLength));
        }    
        return res;    
    }
};