// https://leetcode.com/problems/count-subarrays-with-fixed-bounds

/*You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        /*  2 <= nums.length <= 105
            1 <= nums[i], minK, maxK <= 106
         */
        //Divide the array into multiple subarrays such that each number in each subarray is between minK and maxK inclusive, 
        //solve the previous problem for each subarray, and sum all the answers.
        int sz = nums.size();
        int prevMin = -1;
        int prevMax = -1;
        int bound = -1;
        long long  res = 0;

        for(int i=0; i<sz; i++) {
            if(nums[i]<minK || nums[i]>maxK) {
                bound = i;
                continue; 
            }

            if(nums[i] ==minK) 
                prevMin = i;
            if(nums[i] ==maxK) 
                prevMax = i;
            res += max(0, min(prevMin, prevMax)-bound); 
        }
        return res;
    }
};