// https://leetcode.com/problems/next-permutation

/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, 
if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of 
that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be 
rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*  1 <= nums.length <= 100
            0 <= nums[i] <= 100
        */
        int sz = nums.size();
        if( sz <= 1 )
            return;
        
        int i=sz-1;
        while(i-1>=0 && nums[i-1]>=nums[i]) 
            i--;
        if(i==0) {
            sort(nums.begin(), nums.end());
            return;
        }

        i--;
        int j=sz-1;
        while(nums[j]<=nums[i]) 
            j--;
        swap(nums[i], nums[j]);

        sort(nums.begin()+i+1, nums.end());
        return;      
    }
};