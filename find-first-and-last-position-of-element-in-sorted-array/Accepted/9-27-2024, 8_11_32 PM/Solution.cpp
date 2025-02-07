// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //nums sorted in non-decreasing order
        //find the starting and ending position of a given target value.
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        if(n==1) {
            if(nums[0]==target)
                return {0, 0};
            else 
                return {-1, -1};
        }
        //at least 2 numbers.
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = left + (right-left+1)/2; //ceiling
            if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target) 
                right = mid-1;
            else { //found
                vector<int> res(2,mid);
                while(res[0]-1 >=0 && nums[ res[0]-1 ] == target)
                    res[0]--;
                while(res[1]+1 <n && nums[ res[1]+1 ] == target)
                    res[1]++;
                return res;
            }
        }
        return {-1, -1};
        
    }
};