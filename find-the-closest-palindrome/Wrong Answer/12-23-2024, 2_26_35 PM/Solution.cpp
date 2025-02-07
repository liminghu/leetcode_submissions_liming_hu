// https://leetcode.com/problems/find-the-closest-palindrome

class Solution {
public:
    string nearestPalindromic(string n) { //1 <= n.length <= 18
        int sz = n.size();
        int left = 0;
        int right = sz-1;
        if(sz==1)
            return "0";
        while(left < right) {
            if(n[left] == n[right]) {
                left++;
                right--;
                continue;
            } else if(n[left] > n[right]) {
                n[right] = n[left];
                left++;
                right--;
            } else {  //n[left] < n[right]
                n[right] = n[left];
                left++;
                right--;                
            }
        }
        return n;
    }
};