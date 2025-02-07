// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
        //The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stack;
        for(int i=2*n-1; i>=0; i--) {
            while(!stack.empty() && nums[stack.top()]<=nums[i%n]) {
                stack.pop();
            }
            ans[i%n] = stack.empty()? -1: nums[stack.top()];
            stack.push(i%n); 
        }

        return ans;
    }
};