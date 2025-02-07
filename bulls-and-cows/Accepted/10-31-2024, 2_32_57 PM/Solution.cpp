// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> digit(10, 0);
        int bull = 0;
        int cow = 0;
        for(int i=0; i<secret.size(); i++) {
            char s_i = secret[i];
            char g_i = guess[i];
            if(s_i == g_i)
                bull++;
            else { //The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
                digit[s_i-'0']++;
                if(digit[s_i-'0'] <= 0)
                    cow++;
                digit[g_i-'0']--;  
                if(digit[g_i-'0'] >= 0)
                    cow++;
                              
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};