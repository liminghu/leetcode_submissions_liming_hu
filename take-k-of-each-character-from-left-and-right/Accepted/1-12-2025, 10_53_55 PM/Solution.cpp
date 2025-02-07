// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

class Solution {
public:
    int takeCharacters(string s, int k) {
        //s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k
        int ca=0, cb=0, cc=0;
        int n=s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='a') 
                ca++;
            if(s[i]=='b') 
                cb++;
            if(s[i]=='c')
                cc++;
        }            
        if(ca<k || cb<k || cc<k)
            return -1;

        int ret = 0;
        int j=0; // i and j represents the characters we take from left and right respectively.
        int a=0, b=0, c=0;
        ca -=k;
        cb -=k;
        cc-= k;
        for(int i=0; i<n; i++) {
            while(a<=ca && b<=cb && c<=cc) { //we keep check of count of different alphabets and if any of these count becomes less than k, we start j pointer until the condition is satisfied.
                ret = max(ret,j-i); //[i, j)
                if(j==n)
                    break;
                if(s[j]=='a') a++;
                if(s[j]=='b') b++;
                if(s[j]=='c') c++;
                j++;
            }
            if(s[i]=='a') a--;
            if(s[i]=='b') b--;
            if(s[i]=='c') c--;
        }    
        return n-ret;
    }
};