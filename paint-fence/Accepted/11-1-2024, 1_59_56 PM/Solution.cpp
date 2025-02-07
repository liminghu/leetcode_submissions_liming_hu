// https://leetcode.com/problems/paint-fence

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0)
            return 0;
        if(n==1)
            return k;
        int same = k;
        int diff = k*(k-1);
        for(int i=3; i<=n; i++) {
            int same_tmp = same;
            int diff_tmp = diff;
            same = diff_tmp;
            diff = (same_tmp+diff_tmp)*(k-1);
        }
        return same+diff;
    }
};