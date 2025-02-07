// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
static bool cmp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp); //first dim increasing, then  second dim decreasing.
        vector<int> q;
        for(auto envelope: envelopes) {
            if(q.empty() || envelope[1] > q.back() ) //increasing...
                q.push_back(envelope[1]);
            else {
                auto iter = lower_bound(q.begin(), q.end(), envelope[1]); //first elem >= envelope[1]
                *iter = envelope[1];
            }
        }
        return q.size();
    }
    int maxEnvelopes1(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int ret = 1;
        for(int i=0; i<n; i++) {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};