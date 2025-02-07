// https://leetcode.com/problems/missing-element-in-sorted-array

class Solution {
public:
    int missingElement1(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right) {
            int mid = right-(right-left)/2;
            if(nums[mid] - nums[0] - mid < k) //Calculate the number of missing elements between nums[mid] and nums[0] as nums[mid] - nums[0] - mid.
                left = mid;
            else
                right = mid-1;
        }
        return nums[0] + k + left;
    }
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int startMissing = nums[0]-1;
        while( left <= right ) {
            int pivot = left + (right-left)/2;
            int missing_num = nums[pivot]-(pivot+1+startMissing);
            if(missing_num < k)
                left = pivot +1;
            else
                right = pivot-1;
        };
        //left = right+1;
        /*At the end of the loop, left = right + 1, and the kth missing number is in-between arr[right] and arr[left]. 
        The number of integers missing before arr[right] is arr[right] - right - 1. Hence, 
        the number to return is arr[right] + k - (arr[right] - right - 1) = k + left.
        */
        //        cout << "left:" << left << " right: " << right << endl;

        //int missingBefore = arr[right] - right - 1;
        //return arr[right] + (k - missingBefore);
        return startMissing + left + k; 
    }
};