// https://leetcode.com/problems/missing-element-in-sorted-array

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right) {
            int mid = right-(right-left)/2;
            if(nums[mid] - nums[0] - mid < k) //Calculate the number of missing elements between nums[mid] and nums[0] as nums[mid] - nums[0] - mid.
                left = mid;
            else
                right = mid-1;
        }
        return nums[0]+k+left;
    }
};