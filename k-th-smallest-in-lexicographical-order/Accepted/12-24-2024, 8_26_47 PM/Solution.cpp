// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1; //current prefix node.
        k--;
        while(k>0) {
            int steps = countSteps(n, cur, cur+1); //Calculate the number of steps in the subtree rooted at curr using countSteps(n, curr, curr + 1)
            if(steps<=k) {
                cur++; //Increment curr by 1 to move to the next prefix.
                k-= steps;
            } else {
                cur*=10; //go deeper.
                k--; //number ending with cur, nothing else.
            }
        }
        return cur;
    }
    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while(prefix1 <=n) {
            steps += min((long)(n+1),prefix2)-prefix1; //This ensures the count does not exceed n by capping prefix2 at n + 1 if prefix2 is larger than n.
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};