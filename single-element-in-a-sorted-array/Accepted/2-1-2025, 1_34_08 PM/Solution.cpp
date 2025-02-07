// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r = n-1;
        while(l<r) {
            int mid = (l+r)/2;
            // for each pair, first element takes even position and second element takes odd position
            //this pattern will be missed when single element is appeared in the array.
            //if mid is even, then it's duplicate should be in next index.
	        //or if mid is odd, then it's duplicate  should be in previous index.
            if(mid%2==0 &&nums[mid]==nums[mid+1] || mid%2==1 && nums[mid]==nums[mid-1])
                l = mid+1; //check next half.
            else
                r = mid; //if condition is not satisfied, then the pattern is missed. so, single number must be before mid.
        }
        return nums[l];
    }
};