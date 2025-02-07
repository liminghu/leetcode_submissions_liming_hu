// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        //Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
        if(k==1)
            return nums;
        int n = nums.size();
        vector<int> results(n-k+1, -1);
        int consecutiveCount = 1;
        for(int right = 0; right<n-1; right++) {
            if(nums[right]+1 == nums[right+1])
                consecutiveCount++;
            else
                consecutiveCount = 1;
            if(consecutiveCount>=k) {
                results[right-k+2] = nums[right+1];
            }
        }
        return results;
    }
};