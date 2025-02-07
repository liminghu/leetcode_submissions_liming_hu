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
        int canchange = 0;
        for(int i=0; i<n; i++) {
            if(locked[i]=='0')
                canchange++;
            else if(s[i]=='(')
                open++;
            else if(s[i]==')') {
                if(open>0)
                    open--;
                else if(canchange>0)
                    canchange--;
                else
                    return false;
            }
        }
        int balance = 0;
        for(int i=n-1; i>=0; i--) {
            if(locked[i]=='0') {
                balance--;
                canchange--;
            } else if(s[i]=='(') {
                balance++;
                open--;
            }else if(s[i]==')')
                balance--;
            if(balance>0)
                return false;
            if(canchange==0 && open == 0)
                break;
        }
        return true;
    }
};