// https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays

class Solution {
public:
    /*
    You are given an integer array nums with length n.

The cost of a subarray nums[l..r], where 0 <= l <= r < n, is defined as:

cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

Your task is to split nums into subarrays such that the total cost of the subarrays is maximized, ensuring each element belongs to exactly one subarray.

Formally, if nums is split into k subarrays, where k > 1, at indices i1, i2, ..., ik − 1, where 0 <= i1 < i2 < ... < ik - 1 < n - 1, then the total cost will be:

cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)

Return an integer denoting the maximum total cost of the subarrays after splitting the array optimally.

Note: If nums is not split into subarrays, i.e. k = 1, the total cost is simply cost(0, n - 1).
*/
    long long maximumTotalCost(vector<int>& nums) { //-109 <= nums[i] <= 109; 1 <= nums.length <= 105
        if(nums.size() == 1)
            return nums[0];
    
/*
secondPrev holds the maximum cost for the subarray ending two indices before the current index.
firstPrev holds the maximum cost for the subarray ending at the previous index.
Initially, secondPrev is set to the first element (nums[0]), as the subarray consisting of the first element only has that cost.
firstPrev is set to the maximum of two possible subarrays: [nums[0], nums[1]] or [nums[0], -nums[1]], which corresponds to nums[0] + nums[1] or nums[0] - nums[1].
Iterate Through the Array:

For each element starting from the third one (index 2), calculate the maximum cost considering extending the subarray from two indices back or extending the subarray from one index back.
Update secondPrev and firstPrev for the next iteration.
Return Result:

After processing all elements, firstPrev will contain the maximum total cost.
*/

        //initialize values for dp
        long secondPrev = nums[0];
        long firstPrev = max( nums[0]-nums[1], nums[0]+nums[1]); // 1 split or 2 splits.

        for(int i=2; i<nums.size(); i++) {
            //secondPrev+nums[i-1]-nums[i]: add to the secondPrev split, so in this case the previous num: nums[i-1] is also in that split.
            long current = max(secondPrev+nums[i-1]-nums[i], firstPrev+nums[i]); //firstPrev+nums[i]: add a new split or directly add to the previous split. 

            secondPrev = firstPrev;
            firstPrev = current;
        }

        return firstPrev;
    }
};