// https://leetcode.com/problems/find-the-duplicate-number

/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/
 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n; i++) {
             if(nums[i] == nums[i-1])
                return nums[i];
        };
        return nums[0];

        /*int res = (n-1)*n/2;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        };

        return sum-res;*/
    }
};