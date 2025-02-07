// https://leetcode.com/problems/construct-string-with-repeat-limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
            mp[s[i]]++;
        priority_queue<pair<char, int>> pq;
        for(auto i:mp)
            pq.push({i.first, i.second});
        string ret;
        while(!pq.empty()) {
            char c = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            int len =min(repeatLimit, num);
            for(int i=0; i<len; i++)
                ret+=c;
            char c2;
            int num2 = 0;
            if(num>len) {
                if(!pq.empty()) {
                    c2 = pq.top().first;
                    num2 = pq.top().second;
                    pq.pop();
                    ret += c2;
                    pq.push({c, num-len});
                    if(num2>1)
                        pq.push({c2, num2-1});
                } else
                    return ret;
            }
        }
        return ret;

    }
};