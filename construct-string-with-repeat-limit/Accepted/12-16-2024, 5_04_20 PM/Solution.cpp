// https://leetcode.com/problems/construct-string-with-repeat-limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        int mp[26];
        for(int i=0; i<n; i++)
            mp[s[i]-'a']++;
        priority_queue<pair<char, int>> pq;   //greater queue.
        for(int i=0; i<26; i++) {
            if(mp[i])
                pq.push({i+'a', mp[i]});
        };
        string ret = "";
        while(!pq.empty()) {
            char c1 = pq.top().first;
            int num1 = pq.top().second;
            pq.pop();
            int len =min(repeatLimit, num1);
            for(int i=0; i<len; i++)
                ret += c1;
            char c2;
            int num2 = 0;
            if(num1>len) {
                if(!pq.empty()) {
                    c2 = pq.top().first;
                    num2 = pq.top().second;
                    pq.pop();
                    ret += c2;
                    pq.push({c1, num1-len});
                    if(num2>1)
                        pq.push({c2, num2-1});
                } else
                    return ret;
            }
        };
        return ret;

    }
};