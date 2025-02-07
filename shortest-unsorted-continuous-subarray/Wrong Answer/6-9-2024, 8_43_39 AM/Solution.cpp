// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { //Return the shortest such subarray and output its length.
    //Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
    int ans = 0;
    int n = nums.size();
    stack<int> mono_s; //non decreasing stack. or decreasing.

    int start = n-1;
    int end = 0;

    for(int i=0; i<n; i++) { //increasing
        while(!mono_s.empty() && nums[mono_s.top()]>=nums[i]) {
            start = min(start, mono_s.top());
            mono_s.pop();
        };
        mono_s.push(i);
    }

    mono_s = stack<int>(); //clear

    for(int i=n-1; i>=0; i--) { //decreasing.
        while(!mono_s.empty() && nums[mono_s.top()]<=nums[i]) {
            end = max(end, mono_s.top());
            mono_s.pop();
        };
        mono_s.push(i);
    }

    ans = end-start>0? end-start+1:0;
    return ans;
        
    }
};