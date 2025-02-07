// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n+1, 0);
        for(int i=1; i<=n; i++)
            preSum[i] = preSum[i-1]+nums[i-1];
        deque<int> dq;
        int len = INT_MAX;
        for(int i=0; i<=n; i++) {
            while( !dq.empty() && preSum[dq.back()] >= preSum[i])
                dq.pop_back();
            while( !dq.empty() && preSum[i]- preSum[dq.front()] >= k) {
                len = min(len,  i - dq.front());
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return len==INT_MAX?-1:len;
    }
};