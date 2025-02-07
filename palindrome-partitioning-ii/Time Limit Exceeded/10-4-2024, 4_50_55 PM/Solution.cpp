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
    unordered_map<string,int> mp;
        unordered_map<string,bool> palindrome;
    int minCut(string s) {
        if(mp.find(s)!= mp.end())
            return mp[s];
        if(isPalindrome(s)) {
            mp[s] = 0;
            return 0;
        }
        int size = s.size();        
        if(size == 2) {
            if(s[0] != s[1]) {
                mp[s] = 1;
                return 1;
            }else { 
                return 0;
                mp[s] = 0;
            };
        } 

        int res = INT_MAX;
        for(int i=0; i<size-1; i++) {
            string first = s.substr(0, i+1);
            string second = s.substr(i+1, size-i-1);
            int min_first = minCut(first);
            mp[first] = min_first;
            int min_second = minCut(second);
            mp[second] = min_second;
            //cout << "i: " << i << " first: " << min_first << " second: " << min_second << endl;
            res = min(res, min_first+min_second);
            //cout << "res: " << res << endl;
        };
        mp[s] = res+1;
        return res+1;
    }
    bool isPalindrome( string s) {
        if(palindrome.find(s)!=palindrome.end())
            return palindrome[s];
        int size = s.size();
        if(size<=1) {
            palindrome[s] = true;
            return true;
        }
        int start = 0;
        int end = size-1;
        while(start<end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            } else {
                palindrome[s] = false;
                return false;
            }
        };
        palindrome[s] = true;
        return true;
    }
};