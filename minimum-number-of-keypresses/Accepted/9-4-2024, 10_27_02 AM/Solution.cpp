// https://leetcode.com/problems/minimum-number-of-keypresses

/*You have a keypad with 9 buttons, numbered from 1 to 9, each mapped to lowercase English letters. 
You can choose which characters each button is matched to as long as:
All 26 lowercase English letters are mapped to.
Each character is mapped to by exactly 1 button.
Each button maps to at most 3 characters.
To type the first character matched to a button, you press the button once. To type the second character, 
you press the button twice, and so on.
Given a string s, return the minimum number of keypresses needed to type s using your keypad.
Note that the characters mapped to by each button, and the order they are mapped in cannot be changed.
*/
/*
1 <= s.length <= 105
s consists of lowercase English letters.
*/
class Solution {
public:
    int minimumKeypresses(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++)
            freq[ s[i]-'a' ]++;

        sort(freq.begin(), freq.end()); //increasing.

        int ret = 0;
        for(int i=freq.size()-1; i>=0; i--) {
            if( i >= 26 - 9 )
                ret += freq[i];
            else if ( i >= 26 - 9*2 )
                ret += freq[i]*2;
            else
                ret += freq[i]*3;
        }
        return ret;
    }
};