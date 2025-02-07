// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1; //current prefix node.
        k--;
        while(k>0) {
            int nodes = countNodes(n, cur); //Calculate the number of steps in the subtree rooted at curr using countSteps(n, curr, curr + 1)
            if(nodes<=k) {
                cur++; //Increment curr by 1 to move to the next prefix.
                k-= nodes;
            } else {
                cur*=10; //go deeper.
                k--; //number ending with cur, nothing else.
            }
        }
        return cur;
    }
    int countNodes(int n, long cur) {
        int nodes = 0;
        long next = cur+1;
        while(cur <=n) {
            nodes += min(n-cur+1, next-cur); 
            cur *= 10;
            next *= 10;
        }
        return nodes;
    }
};