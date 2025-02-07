// https://leetcode.com/problems/find-the-n-th-value-after-k-seconds

class Solution {
public:
    int valueAfterKSeconds(int n, int k) { //Return the value of a[n - 1] after k seconds. Since the answer may be very large, return it modulo 109 + 7.
        vector<long long> sum(n,1); //second 0.
        //vector<long long> sum_prev(n,1); //previous loop.

        for(int i=1; i<=k; i++) {
            for(int j=1; j<n; j++) { //update sum from sum_prev.
                sum[j] = sum[j]+sum[j-1];
            };
            //sum_prev = sum;
        };

        int ans = sum[n-1] % (1000000000+7); 
        return ans;
        
    }
};