// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {//1 <= s.length <= 100. s contains only lower and upper case English letters.
    /*A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

        0 <= i <= s.length - 2
        s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.*/  
        //aA
        //Aa
        int n = s.length();
        if(n<=1)
            return s;
        stack<char> st;
        for(int i=0; i<n; i++) {
            if(!st.empty() && bad(st.top(), s[i]))
                st.pop();
            else
                st.push(s[i]);                
        }      
        string res(st.size(), ' ');
        int i=st.size()-1;
        while(!st.empty()) {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
    bool bad(char a, char b) {
        if(isupper(a) && islower(b) && a-'A'==b-'a'  ||   islower(a) && isupper(b) && a-'a'==b-'A')
            return true;
        else
            return false;
    }
};