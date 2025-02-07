// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //sum, idx of nums2. min top.
        for(int num1: nums1)
            pq.push({num1 + nums2[0], 0});
        while(!pq.empty()) {
            int sum = pq.top().first;
            int idx = pq.top().second; //idx of nums2.
            res.push_back({sum-nums2[idx], nums2[idx]});
            if(res.size() == k)
                break;
            pq.pop();

            if(idx+1 < nums2.size())
                pq.push( { sum - nums2[idx] + nums2[idx+1], idx+1 } );
        }
        return res;

    }
};