// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        int dict[256];
        fill_n(dict, 256, 0);
        int start = 0, len = 1, count = 0;
        for(int i=0; i<s.length(); i++) {
            dict[s[i]]++;
            if(dict[s[i]] == 1) {
                count++;
                while(count > 2) {
                    dict[s[start]]--;
                    if(dict[s[start]]==0)
                        count--;
                    start++;
                }
            }
            if(i-start+1>len)
                len = i-start+1;
        }
        return len;
/*        int left = 0;
        int right = 0;
        int n = s.length();
        int ret = 1;
        unordered_map<char, int> mp;
        mp[ s[left] ]++;
        while(left< n && right < n) {
            while( mp.size() <= 2 && (right+1) < n) {
                right++;
                mp[ s[right] ]++;
            }
            if(mp.size() == 3) {
                mp.erase(s[right]);
                right--;
            };
            ret = max(ret, right-left+1);
            mp[s[left]]--;
            if(mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
        return ret;*/
    }
};