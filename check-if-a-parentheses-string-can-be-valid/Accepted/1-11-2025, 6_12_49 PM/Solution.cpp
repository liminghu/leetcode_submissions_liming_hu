// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        //parentheses string s
        int n = s.length();
        //If locked[i] is '1', you cannot change s[i].
        bool ret = false;
        if(n%2 ==1)
            return false;
        int open = 0;
        int close = 0;
        int unpaired = 0;
        int canchange = 0;
        for(int i=0; i<n; i++) {
            if(locked[i]=='0')
                canchange++;
            else if(s[i]=='(')   //The chars which are locked and are open brackets.
                open++;
            else if(s[i]==')') 
                close++;
            unpaired = close - open;
            if(unpaired > canchange) //We need to identify the number of locked brackets which are unpaired, which is equal to number of closed brackets - number of open brackets.
                return false;
        }
        open = 0;
        close = 0;
        unpaired = 0;
        canchange = 0;       
        for(int i=n-1; i>=0; i--) {
            if(locked[i]=='0')
                canchange++;
            else if(s[i]=='(')   //The chars which are locked and are open brackets.
                open++;
            else if(s[i]==')') 
                close++;
            unpaired = open - close; //unpaired, which is (number of open brackets - number of closed brackets) in this case.
            if(unpaired > canchange)
                return false;
        }
        return true;
    }
};