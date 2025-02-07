// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1; //current prefix node.
        k--;
        while(k>0) {
            int steps = countSteps(n, cur, cur+1);
            if(steps<=k) {
                cur++;
                k-= steps;
            } else {
                cur*=10; //go deeper.
                k--;
            }
        }
        return cur;
    }
    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while(prefix1 <=n) {
            steps += min((long)(n+1),prefix2)-prefix1;
            prefix1 *=10;
            prefix2 *=10;
        }
        return steps;
    }
};