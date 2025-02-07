// https://leetcode.com/problems/search-in-rotated-sorted-array

/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index 
k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], 
nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated 
at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of 
target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*  1 <= nums.length <= 5000
            -104 <= nums[i] <= 104
            All values of nums are unique.
            nums is an ascending array that is possibly rotated.
            -104 <= target <= 104
        */
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right) {
            int mid = ( left + right ) / 2;
            if(nums[mid] == target)
                return mid;

            //subarray on mid's left is sorted
            if(nums[mid] >= nums[left]) {
                if( target >= nums[left] && target < nums[mid] )
                    right = mid -1;
                else
                    left = mid + 1;
            } else { //subarray on mid's right is sorted
                if(target <=nums[right] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid -1;            
            };
        }
        return -1;

    }
};