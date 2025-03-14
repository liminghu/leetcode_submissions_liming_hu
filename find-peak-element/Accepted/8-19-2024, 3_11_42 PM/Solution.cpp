// https://leetcode.com/problems/find-peak-element

/*A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is 
always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
            1 <= nums.length <= 1000
            -231 <= nums[i] <= 231 - 1
            nums[i] != nums[i + 1] for all valid i.
        */
        int l =0;
        int r = nums.size() -1;
        while(l<r) {
            int mid = (l+r)/2;
            if(nums[mid] > nums[mid+1])
                r = mid;
            else
                l = mid+1;
        }

        return l;
    }
};