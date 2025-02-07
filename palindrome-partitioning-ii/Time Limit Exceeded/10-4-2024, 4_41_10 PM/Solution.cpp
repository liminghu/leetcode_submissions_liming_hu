// https://leetcode.com/problems/palindrome-partitioning-ii

/*
Given a string s, partition s such that every 
substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1
 

Constraints:
1 <= s.length <= 2000
s consists of lowercase English letters only.
*/
class Solution {
public:
    int minCut(string s) {
        if(isPalindrome(s))
            return 0;

        int size = s.size();        
        if(size == 2) {
            if(s[0] != s[1])
                return 1;
            else 
                return 0;
        } 

        int res = INT_MAX;
        for(int i=0; i<size-1; i++) {
            int min_first = minCut(s.substr(0, i+1));
            int min_second = minCut(s.substr(i+1, size-i-1));
            //cout << "i: " << i << " first: " << min_first << " second: " << min_second << endl;
            res = min(res, min_first+min_second);
            //cout << "res: " << res << endl;
        };
        return res+1;
    }
    bool isPalindrome( string s) {
        int size = s.size();
        if(size<=1)
            return true;
        int start = 0;
        int end = size-1;
        while(start<end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            } else
                return false;
        };
        return true;
    }
};