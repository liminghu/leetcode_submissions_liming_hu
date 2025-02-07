// https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) { //1 <= li <= ri <= 109
        //coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.
        //The segments that coins contain are non-overlapping.
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long res = 0;
        long long cur = 0;
        int j = 0;
        //start at coins[i][0]
        for(int i=0; i<n; i++) {
            while(j<n && coins[j][1] <= coins[i][0]+k-1) {
                cur += 1LL * (long long)(coins[j][1]-coins[j][0]+1) * (long long)coins[j][2];
                j++;
            };
            if(j<n) {
                long long part = 1LL * (long long)max(0, coins[i][0]+k-1-coins[j][0]+1) * (long long)coins[j][2];
                res = max(res, cur+part);
            }
            cur -= 1LL*(long long)(coins[i][1]-coins[i][0]+1) * (long long)coins[i][2];
        }
        //end at coins[i][1]
        cur = 0;
        j = 0;
       for(int i=0; i<n; i++) {
            cur += 1LL*(long long)(coins[i][1]-coins[i][0]+1) * (long long)coins[i][2];
            while(coins[j][1] < coins[i][1]-k+1) {
                cur -= 1LL * (long long)(coins[j][1]-coins[j][0]+1) * (long long)coins[j][2];
                j++;
            };
            long long part = 1LL * (long long)max(0, coins[i][1]-k-coins[j][0]+1) * (long long)coins[j][2];
             res = max(res, cur-part);
        }    
        return res;    
    }
};