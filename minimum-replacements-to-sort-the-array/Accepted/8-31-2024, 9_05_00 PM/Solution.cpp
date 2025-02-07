// https://leetcode.com/problems/minimum-replacements-to-sort-the-array

/*
You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.
For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.
*/
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // 1<= nums.length <= 105
        // 1 <= nums[i] <= 109
        int n = nums.size();
        long long  res = 0;

        for(int i=n-2; i>=0; i--) {
            if(nums[i]<=nums[i+1])
                continue;
            //nums[i] > nums[i+1]
            int numReplace = 0;
            numReplace =ceil( (double)nums[i] / nums[i+1]);
            nums[i] = nums[i] / numReplace; //get the smaller one.
            res += numReplace-1;

        };

        return res;
    }
};