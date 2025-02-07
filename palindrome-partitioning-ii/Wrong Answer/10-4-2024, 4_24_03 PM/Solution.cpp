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
        int size = s.length();        
        if(size <=1)
            return 0;
        if(size == 2)
            return 1;

        int res = INT_MAX;
        for(int i=1; i<size-1; i++) {
            int min_first = minCut(s.substr(0, i+1));
            int min_second = minCut(s.substr(i+1, size-i-1));
            res = min(res, min_first+min_second);
        };
        return res;
    }
};