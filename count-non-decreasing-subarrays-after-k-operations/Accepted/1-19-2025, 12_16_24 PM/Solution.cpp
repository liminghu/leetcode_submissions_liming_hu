// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        deque<int> dq;
        int left = 0;
        int right = 0;
        long long reqOps = 0;
        long long ret = 0;
        int n = nums.size();
        for( ; right<n; right++ ){
            while( !dq.empty() && nums[right] > nums[dq.back()] ){
                int curr = dq.back();
                dq.pop_back();
                int next = !dq.empty()? dq.back(): left-1;
                reqOps += (long long) ( nums[right] - nums[curr] ) * (long long)(curr-next);
            }
            dq.push_back( right );
            while( !dq.empty() && reqOps > (long long)k ){
                reqOps -= (long long) ( nums[dq.front()] - nums[left] );
                if( dq.front() == left )
                    dq.pop_front();
                left++;
            }
            ret += ( right - left + 1 );
        }
        return ret;
    }
};