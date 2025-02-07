// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements

class Solution {
public:
    /*
    You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.

You repeat the following procedure n / 2 times:

Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.
*/
    
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=0;
        int right = nums.size()-1;
        double min_average = 200;
        while(left<right) {
            int sum = nums[left]+nums[right];
            if(sum<min_average)
                min_average = sum;
            left++;
            right--;
        };
        return min_average/2;
        
    }
};