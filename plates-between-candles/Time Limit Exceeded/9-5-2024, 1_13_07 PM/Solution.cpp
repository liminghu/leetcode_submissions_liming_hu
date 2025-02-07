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
        vector<int> candles; //pos, {idx of candle location until pos}
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(s[i] == '|' )
                candles.push_back(i);
        };

        vector<int> ret;
        for(auto query:queries) {
            //query[0], query[1]
            int res = 0;
            int candle_i = lower_bound(candles.begin(), candles.end(), query[0]) - candles.begin(); //{2}
            int candle_j = upper_bound(candles.begin(), candles.end(), query[1]) - 1 - candles.begin();  //{2,5}
            for(auto k=candle_i+1; k<=candle_j; k++) { 
                    res += candles[k] - candles[k-1] - 1;
            };
            ret.push_back(res);

        }
        return ret;
    }
};