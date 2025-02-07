// https://leetcode.com/problems/plates-between-candles

/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed 
string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' 
represents a candle.
You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes 
the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates 
between candles that are in the substring. A plate is considered between candles if there is at 
least one candle to its left and at least one candle to its right in the substring.
For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates 
between candles in this substring is 2, as each of the two plates has at least one candle in the substring 
to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.
*/
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp; //pos, {idx of candle location until pos}
        int n = s.length();
        mp[-1] = {-1}; //vector<int>();
        for(int i=0; i<n; i++) {
            mp[i] = mp[i-1];
            if(s[i] == '|' )
                mp[i].push_back(i);
        };

        vector<int> ret;
        for(auto query:queries) {
            //query[0], query[1]
            int res = 0;
            vector<int> candle_i = mp[ query[0] ]; //{2}
            //if(query[0] == candle_i.back())
            //    candle_i.pop_back();
            vector<int> candle_j = mp[ query[1] ];  //{2,5}
            for(int k=candle_i.size(); k<candle_j.size(); k++) { //exclude candle_i
                if(candle_j[k-1]!=-1 && candle_j[k-1] >= query[0])
                    res += candle_j[k] - candle_j[k-1]-1;
            };
            ret.push_back(res);

        }
        return ret;
    }
};