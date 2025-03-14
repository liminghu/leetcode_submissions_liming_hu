// https://leetcode.com/problems/maximum-score-from-removing-substrings

/*You are given a string s and two integers x and y. You can perform two types of operations any number of times.
Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.
*/
class Solution {
public:
    //unordered_map<string, int> gain;
    int maximumGain(string s, int x, int y) { //1 <= s.length <= 105; 1 <= x, y <= 104; s consists of lowercase English letters.
       int sz = s.length();
       if( sz <= 1 )
            return 0;
        if(sz == 2) {
            if( s == "ab")
                return x;
            else if( s == "ba" )
                return y;
            else
                return 0;  
        } 
        stack<char> st;

        int points = 0;  
        int top = 0;
        int bottom = 0;
        char first = 'a';
        char second = 'b';
        if( x >= y) { //remove ab first. after remove all ab, there is no chance we will have ab any more.
            top = x;
            bottom = y;
            first = 'a';
            second = 'b';
        } else {
            top = y;
            bottom = x;
            first = 'b';
            second = 'a';           
        };
        for(int i=0; i<sz; i++) {
            if( !st.empty() && st.top() == first && s[i] == second) {
                st.pop();
                points += top; 
            } else 
                st.push(s[i]);
        }

        string new_s = "";
        while( !st.empty() ) {
            new_s.push_back(st.top());
            st.pop();
        }

        reverse(new_s.begin(), new_s.end());
        for(int i=0; i<new_s.length(); i++) {
            if( !st.empty() && st.top() == second && new_s[i] == first ) {
                st.pop();
                points += bottom; 
            } else
                st.push(new_s[i]);
        }

        return points;


/*        if( s.length() <= 1 )
            return 0;
        if(s.length()==2) {
            if( s=="ab")
                return x;
            else if(s=="ba")
                return y;
            else
                return 0;   
        }

        int sz = s.length();
        int maxGain = 0;
        if( gain.find(s) != gain.end() )
            return gain[s];

        for(int i=0; i<sz-1; i++) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                string s1 = s.substr( 0, i );
                string s2 = s.substr( i+2, sz-i-2 );
                maxGain = max( maxGain, x + maximumGain( s1 + s2, x, y));
            } else if(s[i] == 'b' && s[i+1] == 'a') {
                string s1 = s.substr( 0, i );
                string s2 = s.substr( i+2, sz-i-2 );
                maxGain =max( maxGain, y + maximumGain( s1 + s2, x, y));
            } else if( s[i] != 'a' && s[i] != 'b') {
                string s1 = s.substr(0, i);
                int max1 = maximumGain(s1, x, y);
                string s2 = s.substr(i+1, sz-i-1);
                int max2 = maximumGain(s2, x, y);
                maxGain = max( maxGain, max1 + max2 );
            } else
                continue;
        }
        gain[s] = maxGain;
        return maxGain;  */  
    }
};