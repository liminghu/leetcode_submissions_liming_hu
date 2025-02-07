// https://leetcode.com/problems/binary-search

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to 
search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {//All the integers in nums are unique. nums is sorted in ascending order.
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid = 0;
        while( left <= right ) {
            mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) 
                left = mid+1;
            else 
                right = mid-1;
        };
        return -1;
        
    }
};