// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { //Return the shortest such subarray and output its length.
    //Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
    int ans = 0;
    int n = nums.size();
    stack<int> nd_s; //non decreasing stack.

    int start = n-1;
    int end = 0;

    for(int i=0; i<n; i++) {
        while(!nd_s.empty() && nums[nd_s.top()]>=nums[i]) {
            start = min(start, nd_s.top());
            nd_s.pop();
        };
        nd_s.push(i);
    }

    nd_s = stack<int>(); //clear

    for(int i=n-1; i>=0; i--) { //decreasing.
        while(!nd_s.empty() && nums[nd_s.top()]<nums[i]) {
            end = max(end, nd_s.top());
            nd_s.pop();
        };
        nd_s.push(i);
    }

    ans = end-start>0? end-start+1:0;
    return ans;
        
    }
};