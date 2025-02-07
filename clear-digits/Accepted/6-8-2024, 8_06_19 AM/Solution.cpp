// https://leetcode.com/problems/clear-digits

/*You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
*/
class Solution {
public:
    string clearDigits(string s) { 
//s consists only of lowercase English letters and digits.
//The input is generated such that it is possible to delete all digits.
        string ans;
        int n = s.length();
        
        for(int i=n-1; i>0; i--) {
            if(s[i]==-1)
                continue;
            //look for digit.
            if( !(s[i]>='0' && s[i] <='9') ) { //letter
                continue;
            }
            //found a digit.
            s[i] = -1; //marked as 'to be deleted.'
            //look for a non digit.
            for(int j=i-1; j>=0; j--) {
                if( !((s[j]>='0' && s[j] <='9') || s[j]==-1) ) {//letter
                    s[j] = -1;  //marked as 'to be deleted' 
                     break; //letter.
                };                
            }
        }

        for(int i=0; i<n; i++) {
            if(s[i]!=-1)
                ans+=s[i];
        };
        return ans;
        
    }
};