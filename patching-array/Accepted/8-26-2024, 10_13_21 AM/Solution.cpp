// https://leetcode.com/problems/patching-array

/*Given a sorted integer array nums and an integer n, add/patch elements to the array such 
that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
Return the minimum number of patches required.
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        /*  1 <= nums.length <= 1000
            1 <= nums[i] <= 104
            nums is sorted in ascending order.
            1 <= n <= 231 - 1
        */
        long miss = 1; //Let miss be the smallest sum in [0,n] that we might be missing
        int res = 0;
        int sum = 0;
        int i = 0;
        /*Then if we have a number num <= miss in the given array, we can add it to those 
        smaller sums to build all sums in [0,miss+num). If we don't, then we must add such 
        a number to the array, and it's best to add miss itself, to maximize the reach.*/
        while(miss <= n) {
            if(i<nums.size() && nums[i] <=miss) {
                miss+= nums[i];
                i++;
            } else {
                miss += miss;
                res++;
            }
        }
        return res;
    }
};