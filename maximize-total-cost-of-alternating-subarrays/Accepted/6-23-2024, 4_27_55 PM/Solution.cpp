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
    long long maximumTotalCost(vector<int>& nums) { //-109 <= nums[i] <= 109

//At each step - we have to decide whether to include the current num in sum or whether to start a new sum
//Include num in Best Sum so far (add num to max of sums)
//Or Start a fresh sum , by flipping num & adding to curr best sum


        //pos is last element is positive sign.
        long long pos = -1e15;
        //neg is last element is negative sign.
        long long neg = 0;

        long long temp = 0;

        for(int num: nums) {
            //After the neg, we need to append a positive A[i]
            //After the pos, we can append a positive/negative A[i]

            temp = neg;
            neg = pos - num;

            pos = max(pos, temp)+num;
        }

        return max(pos, neg);
        
        
    }
};