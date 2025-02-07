// https://leetcode.com/problems/decode-ways

/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some 
codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in 
any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.
Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/
class Solution {
public:
    int numDecodings(string s) {
        /*"1" -> 'A'
          "2" -> 'B'
           ...
          "25" -> 'Y'
          "26" -> 'Z'
        */
        int n = s.length();
        if( n == 0 )
            return 0;
        return numDecodings(s, 0, n);
    }
    int numDecodings(string s, int l, int size) {
        if( m_ways.find(l) != m_ways.end() )
            return m_ways[l];

        if( s[l] == '0' )
            return 0;
        if( l >= size )
            return 1;   //single digit or empty.

        int w = numDecodings(s, l+1, size);
        int prefix2 = (s[1]-'0') * 10 + (s[l+1]-'0');
        if( prefix2 <= 26 )
            w += numDecodings(s, l+2, size);
        m_ways[l] = w;
        return w; 
    }
    unordered_map<int, int> m_ways;
};