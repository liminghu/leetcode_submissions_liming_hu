// https://leetcode.com/problems/swap-adjacent-in-lr-string

class Solution {
public:
    bool canTransform(string start, string result) {//Both start and result will only consist of characters in 'L', 'R', and 'X'.
        int n = start.length();
        //a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR"
        if(result.length()!=n)
            return false;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(start[i]=='X')
                count++;
            if(result[i]=='X')
                count--;
        }
        if(count!=0)
            return false;
        int i=0, j=0;
        while(i<n && j<n) {
            while(i<n && start[i]=='X')
                i++;
            while(j<n && result[j]=='X')
                j++;
            if(i==n || j==n)
            return i==n && j==n;
            if(start[i]!=result[j])
                return false;
            if(start[i]=='L' && i<j) //'L' can only move to left.
                return false;
           if(start[i]=='R' && i>j) //'R' can only move to right.
                return false;            
            i++;
            j++;
        }
        return true;

    }
};