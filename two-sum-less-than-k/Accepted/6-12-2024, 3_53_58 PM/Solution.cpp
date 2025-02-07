// https://leetcode.com/problems/two-sum-less-than-k

class Solution {
public:
/*
    Given an array nums of integers and integer k, return the maximum sum such that 
    there exists i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.
*/
    int twoSumLessThanK(vector<int>& nums, int k) { //1 <= nums.length <= 100 1 <= nums[i] <= 1000 1 <= k <= 2000
        int ans = -1;
        int count[1001] = {}; //first element will be ignored.
        for(int num: nums) {
            count[num]++;
        };

        int low = 1;
        int high = 1000;
        while( low <= high ) {
            if( low+high >=k  || count[high] == 0  ) {
                high--;
            } else {
                if( (count[low] > 0 && low<high ) || 
                    (count[low] > 1 && low==high) ) {
                        ans = max(ans, low+high);
                    };
                    low++;
            }
        }
        return ans;
    }
};