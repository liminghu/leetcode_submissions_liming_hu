// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        /*Find a pair of indices (i, j) such that:
            i != j,
            abs(i - j) <= indexDiff.
            abs(nums[i] - nums[j]) <= valueDiff, and
            Return true if such pair exists or false otherwise.
        */
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=max(0, i-indexDiff); j<=min(i+indexDiff, n-1); j++) {
                long valdiff = abs(nums[i]-nums[j]);
                if(valdiff <= (long)valueDiff && i != j )
                    return true;
            }
        }
        return false;
    }
};