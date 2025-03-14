// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }
        
        for(int i=0; i<k-1; i++) {
            pq.pop();
        }
        
        return pq.top();
    }
};