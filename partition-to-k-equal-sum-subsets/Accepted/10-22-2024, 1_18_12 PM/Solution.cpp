// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

/*
Given an integer array nums and an integer k, return true if it is possible to divide this array 
into k non-empty subsets whose sums are all equal.

 Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false
 
Constraints:
1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/
class Solution {
public:
    bool visited[16];
    int total;
    int k;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->k = k;
        int n = nums.size();
        total = 0;
        for(int i=0; i<n; i++)
            total += nums[i];
        if( total % k !=0 )
            return false;
        sort(nums.begin(), nums.end());
        return dfs(nums, 0, 0, 0); //int cur, int grp, int sum
    }
    bool dfs(vector<int>& nums, int cur, int grp, int sum) {
        if(grp == k)
            return true;
        if(sum > total/k)
            return false;
        if(sum == total/k)
            return dfs(nums, 0, grp+1, 0);
        int last = -1;
        for(int i=cur; i<nums.size(); i++) {
            if(visited[i])
                continue;
            if(nums[i] == last)
                continue;
            visited[i] = true;
            last = nums[i];
            if( dfs(nums,i+1, grp, sum+nums[i]))
                return true;
            visited[i] = false;
        }
        return false;
    }
};