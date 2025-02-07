// https://leetcode.com/problems/missing-number

/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        for(int i=0; i<n; i++)
            sum -= nums[i];
        return sum; 
    }
};