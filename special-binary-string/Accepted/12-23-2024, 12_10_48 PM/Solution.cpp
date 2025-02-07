// https://leetcode.com/problems/special-binary-string

class Solution {
public:
    string makeLargestSpecial(string s) {//s is a special binary string.
        int count = 0;
        int i=0;
        vector<string> res;
        int n = s.size();
        for(int j=0; j<n; j++) { //Split S into several special strings (as many as possible).
            if(s[j]=='1')
                count++;
            else
                count--;
            if(count ==0) {
                string sub = s.substr(i+1, (j-1)-(i+1)+1);
                res.push_back('1' + makeLargestSpecial(sub)+'0'); //Special string starts with 1 and ends with 0. Recursion on the middle part.
                i=j+1;
            }
        }
        sort(res.begin(), res.end(), greater<string>()); //Sort all special strings in lexicographically largest order.
        string ret;
        for(int i=0; i<res.size(); i++)
            ret += res[i];
        return ret;
    }
};