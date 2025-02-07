// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0;
        int right = 0;
        int n = s.length();
        int ret = 1;
        unordered_map<char, int> mp;
        mp[ s[left] ]++;
        while(right < n) {
            while( mp.size() <= 2 && right < n) {
                right++;
                mp[ s[right] ]++;
            }
            if(mp.size() == 3) {
                mp.erase(s[right]);
                right--;
            };
            ret = max(ret, right-left+1);
            mp[ s[left] ]--;
            if(mp[ s[left] ] == 0 )
                mp.erase( s[left] );
            left++;
        }
        return ret;
    }
};