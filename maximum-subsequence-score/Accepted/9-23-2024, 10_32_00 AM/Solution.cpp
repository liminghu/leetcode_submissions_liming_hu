// https://leetcode.com/problems/maximum-subsequence-score

/*
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. 
You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:
The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.
A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[j] <= 105
1 <= k <= n
*/
using LL = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++) 
            arr.push_back({nums2[i], nums1[i]});
        sort(arr.rbegin(), arr.rend()); // decreasing...
        
        int minVal = INT_MAX;
        priority_queue<int, vector<int>, greater<>> pq;
        LL sum = 0;  
        LL ret = 0;
        for(int i=0; i<n; i++) { //suppose the pq has size k.
            minVal = arr[i].first;
            sum += arr[i].second;
            pq.push(arr[i].second); //for sum.
            if(pq.size() > k) {
                sum -= pq.top(); //if pq.top() index is i?
                pq.pop();
            }
            if(pq.size() == k)
                ret = max(ret, sum*minVal); //if that's the case, the ret will not be updated.

        }
        return ret;
    }
};