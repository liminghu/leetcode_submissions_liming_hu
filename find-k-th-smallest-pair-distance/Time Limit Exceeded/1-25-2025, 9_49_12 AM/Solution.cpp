// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> pq; //greater top.
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                pq.push(abs(nums[i]-nums[j]));
            }
        };
        while(pq.size()>k) 
            pq.pop();
        return pq.top();
    }
};