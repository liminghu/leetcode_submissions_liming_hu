// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:

    string trim(string s) {
        string ans=s;
        int n=s.length();
        int i=0, j=n-1;
        while(s[i]==' ') {
            i++;
        };
        while(s[j]==' ') {
            j--;
        };
        ans = s.substr(i, j-i+1);
        return ans;
    }
    string reverseWords(string s) { //A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
    //Note that s may contain leading or trailing spaces or multiple spaces between two words. 
    //The returned string should only have a single space separating the words. Do not include any extra spaces.
        string ans;
        s = trim(s); //trim
        reverse(s.begin(), s.end()); //reverse
        int n = s.length();
        int i=0;
        int end=0;

        for(int start=0;start<n; start++) {
            if(s[start]!= ' ') {
                if(i!=0) s[i++] = ' '; //add a space first.

                end = start;
                while(end<n && s[end]!= ' ') 
                    s[i++]=s[end++];

                reverse(s.begin()+i-(end-start), s.begin()+i);
                start = end; 
            }
        };

        s.erase(s.begin()+i, s.end());
        return s;
        
    }
};