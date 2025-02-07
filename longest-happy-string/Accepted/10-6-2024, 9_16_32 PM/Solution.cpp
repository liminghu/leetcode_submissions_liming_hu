// https://leetcode.com/problems/longest-happy-string

/*A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. 
If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        /*
        A string s is called happy if it satisfies the following conditions:
        s only contains the letters 'a', 'b', and 'c'.
        s does not contain any of "aaa", "bbb", or "ccc" as a substring.
        s contains at most a occurrences of the letter 'a'.
        s contains at most b occurrences of the letter 'b'.
        s contains at most c occurrences of the letter 'c'.
        */
        priority_queue<pair<int,int>> pq; //pair: freq, char
        if( a > 0 )
            pq.push({a, 'a'});
        if( b > 0 )
            pq.push({b, 'b'});
        if( c > 0 )
            pq.push({c, 'c'});  

        string ret;
        while(!pq.empty()) {
            if( pq.size() == 1 ) {
                int k = min( pq.top().first, 2);
                for(int i=0; i<k; i++)
                    ret.push_back(pq.top().second);
                return ret;
            }
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            int k= min( 1 + x.first - y.first, 2);
            for(int i=0; i<k; i++)
                ret.push_back(x.second);
            ret.push_back(y.second);
            x.first -= k;
            y.first -= 1;
            if(x.first > 0 )
                pq.push(x);
            if(y.first > 0)
                pq.push(y);
        }                  
        return ret;
    }
};