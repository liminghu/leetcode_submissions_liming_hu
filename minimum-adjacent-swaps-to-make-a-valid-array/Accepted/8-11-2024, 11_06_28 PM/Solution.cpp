// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array

/*You are given a 0-indexed integer array nums.

Swaps of adjacent elements are able to be performed on nums.

A valid array meets the following conditions:

The largest element (any of the largest elements if there are multiple) is at the rightmost position in the array.
The smallest element (any of the smallest elements if there are multiple) is at the leftmost position in the array.
Return the minimum swaps required to make nums a valid array.
*/
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        /*  1 <= nums.length <= 105
            1 <= nums[i] <= 105
        */
        int sz = nums.size();
        if(sz<=1)
            return 0;

        int min_num = INT_MAX;
        int min_index = 0;
        int max_num = INT_MIN;
        int max_index = 0;
        for(int i=0; i<sz; i++) {
            if(nums[i] >= max_num) {
                max_index = i;
                max_num = nums[i];
            };
        };

        int res = 0;
        res = (sz-1) - max_index;
        for(int j=max_index; j<sz-1; j++) {
            nums[j] = nums[j+1];
        }
        nums[sz-1] = max_num;

        for(int i=0; i<sz; i++) {
            if(nums[i] < min_num) {
                min_index = i;
                min_num = nums[i];
            };
        };

        res = res + min_index;
        return res;

    }
};