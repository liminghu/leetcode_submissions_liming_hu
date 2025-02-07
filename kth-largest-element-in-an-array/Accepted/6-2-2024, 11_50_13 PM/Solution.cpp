// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_pq;
        int n = nums.size();
        
        if(k>n)
            return -1;
        for(int i=0; i<n; i++) {
            max_pq.push(nums[i]);
        };
        
        int j=0;
        int ans=0;
        while(j<k) {
            ans = max_pq.top();
            max_pq.pop();
            j++;
        };
        return ans;
        
        
    }
};