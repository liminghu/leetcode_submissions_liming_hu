// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    unordered_map<int, int> visited;
    int integerReplacement(int n) {
        if(n==1)
            return 0;
        if(visited.find(n) == visited.end()) {
            if( (n & 1) == 1 )
                visited[n] = 2 + min(integerReplacement(n/2), integerReplacement(n/2 + 1 ) );
            else
                return 1+ integerReplacement(n/2);
         }
         return visited[n];
    }
};