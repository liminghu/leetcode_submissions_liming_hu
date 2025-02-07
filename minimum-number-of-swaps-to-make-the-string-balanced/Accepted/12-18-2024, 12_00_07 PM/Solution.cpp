// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int balance = 0;
        int j = n-1;
        int swaps = 0;
        for(int i=0; i<n-1; i++) {
            if(s[i]=='[')
                balance++;
            else
                balance--;
            if(balance<0) {
                while(i<j && s[j]!='[')
                    j--;
                swap(s[i], s[j]);
                swaps++;
                balance=1;
            }
        }
        return swaps;
    }
};