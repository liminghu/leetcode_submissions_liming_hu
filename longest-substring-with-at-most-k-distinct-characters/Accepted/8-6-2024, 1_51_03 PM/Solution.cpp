// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp; //num, count
        int sz = s.length();
        
        int result = 0;
        int i = 0;
        for(int j=0; j<sz; j++) {
            mp[s[j]]++;
            while(mp.size() > k) {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            result = max(result,  j-i+1);
        }
        return result;
    }
};