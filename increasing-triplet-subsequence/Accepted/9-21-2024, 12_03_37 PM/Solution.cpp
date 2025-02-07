// https://leetcode.com/problems/increasing-triplet-subsequence

/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k)
 such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
 1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        if( sz < 3 )
            return false;
        
        vector<int> leftMin(sz,0);
        vector<int> rightMax(sz,0);

        leftMin[0] = INT_MAX;
        for(int i=1; i<sz; i++)
            leftMin[i] = min(leftMin[i-1], nums[i-1]);

        rightMax[sz-1] = INT_MIN;
        for(int i=sz-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], nums[i+1]);    

        for(int j=0; j<sz; j++) { //i < j < k and nums[i] < nums[j] < nums[k]
            if(leftMin[j] <nums[j] && nums[j] < rightMax[j])
                return true;
        }
        return false;        
    }
};