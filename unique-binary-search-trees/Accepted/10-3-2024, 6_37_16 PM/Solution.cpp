// https://leetcode.com/problems/unique-binary-search-trees

/*
Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

Constraints:
1 <= n <= 19
*/
class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        
        int res = 0;
        for(int i=0; i<n; i++) { //using i as the root.
            res += numTrees(i) * numTrees(n-1-i);
        }
        return res;
    }
};