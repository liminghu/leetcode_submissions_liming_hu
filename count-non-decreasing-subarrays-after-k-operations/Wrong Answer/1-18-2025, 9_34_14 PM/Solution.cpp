// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        long long res = 0;
        deque<int> q;
        for (int j = 0, i = 0; j < nums.size(); ++j) {
            while (!q.empty() && nums[q.back()] < nums[j]) {
                int r = q.back();
                q.pop_back();
                int l = q.empty() ? i - 1 : q.back();
                k -= 1L * (r - l) * (nums[j] - nums[r]);
            }
            q.push_back(j);
            while (k < 0) {
                k += nums[q.front()] - nums[i];
                if (q.front() == i) {
                    q.pop_front();
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};