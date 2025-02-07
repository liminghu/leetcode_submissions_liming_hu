// https://leetcode.com/problems/partition-labels

/*
You are given a string s. We want to partition the string into as many parts as possible so that each
 letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant 
string should be s.

Return a list of integers representing the size of these parts.
1 <= s.length <= 500
s consists of lowercase English letters.
*/
//Hash table + Greedy.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        vector<int> last_idx(26,0);
        for(int i=0; i<n; i++) 
            last_idx[ s[i]-'a'] = i;
        int left = 0;
        int right = 0;
        for(int i=0; i<n; i++) {
            right = max(right, last_idx[ s[i]-'a' ] );
            if( i == right ) {//i is the last idx.
                ans.push_back( right- left + 1 );
                left = right+1;
            };
        }
        return ans;
    }
};