// https://leetcode.com/problems/find-longest-awesome-substring

class Solution {
public:
    int longestAwesome(string s) {
        /*  1 <= s.length <= 105
            s consists only of digits.
        */
        unordered_map<int,int> mp; //prefix encode -> lowest idx.
        mp[0] = -1; //????  j-mp[key]   0-mp[0] = 1.
        vector<int> count(10, 0);
        int ret = 0;
        for(int j=0; j<s.length(); j++) {
            count[s[j]-'0']++;
            int key = count2key(count);
            if(mp.find(key)!=mp.end()) {
                ret = max(ret, j-mp[key]); //mp[key] is not included. open.
            } else 
                mp[key] = j;

            for(int k=0; k<10; k++) {
                int newKey = key;
                if( ((key>>k) & 1) == 0 )
                    newKey += (1<<k);
                else
                    newKey -= (1<<k);
                if(mp.find(newKey) != mp.end()) {
                    ret = max(ret, j-mp[newKey]);
                }
            }
        }
        return ret;
    }

    int count2key(vector<int>& count) {
        int key = 0;
        for(int i=0; i<10; i++) {
            key+= ((count[i]%2)<<i);
        }
        return key;
    }
};