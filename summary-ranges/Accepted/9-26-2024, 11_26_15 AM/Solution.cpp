// https://leetcode.com/problems/summary-ranges

/*
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, and there is no 
integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //nums: sorted
        int n = nums.size();
        vector<string> ans;
        for(int i=0; i<n; i++) {
            //range.
            int left = nums[i];
            int right = nums[i];
            int j = i;
            while(j+1 <n && nums[j+1]==nums[j]+1)
                j++;
            right = nums[j];
            string range_i;
            if( j== i)
                range_i = to_string(nums[i]);
            else {
                range_i += to_string(nums[i]);
                range_i += "->";
                range_i += to_string(nums[j]);
            };
            ans.push_back(range_i);
            i = j;
        };
        return ans;
        
    }
};