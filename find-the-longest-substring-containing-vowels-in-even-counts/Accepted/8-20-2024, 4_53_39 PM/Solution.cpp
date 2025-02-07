// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp; //key ->the earliest idx.
        vector<int> count(5,0);
        mp[0] = -1;
        int ret = 0;
        for(int j=0; j<s.length(); j++) {
            if(s[j] == 'a') {
                count[0]++;
            } else if(s[j] == 'e') {
                count[1]++;
            } else if(s[j] == 'i') {
                count[2]++;
            } else if(s[j] == 'o') {
                count[3]++;
            } else if(s[j] == 'u') {
                count[4]++;
            };
            int key = count2key(count);
            if(mp.find(key) !=mp.end()) {
                ret = max(ret, j-mp[key]);
            } else 
                mp[key] = j;
        }
        return ret;
    }
    int count2key(vector<int> count) {
        int key = 0;
        for(int i=0; i<5; i++) {
            if(count[i]%2 == 1)
                key += (1<<i);
        }
        return key;
    }
};