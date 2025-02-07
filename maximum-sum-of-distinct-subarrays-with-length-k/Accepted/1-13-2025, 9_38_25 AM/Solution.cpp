// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0;
        int n = nums.size();
        if(n<k)
            return 0;
        unordered_map<int, int> num2index;
        long long cur_sum = 0;
        int left = 0, right = 0;
        for(int right=0; right<n; right++) {
            int curNum = nums[right];
            int lastIndx = num2index.count(curNum)? num2index[curNum]: -1;
            while(left <= lastIndx || right-left+1 > k ) {
                cur_sum -= nums[left];
                left++;
            }
            num2index[curNum] = right;
            cur_sum += nums[right];
            if(right-left+1==k)
                ret = max(ret, cur_sum);
        }
        return ret;
    }
};