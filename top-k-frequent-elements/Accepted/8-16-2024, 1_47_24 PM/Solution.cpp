// https://leetcode.com/problems/top-k-frequent-elements

//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; //num, count
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        priority_queue<pair<int,int>> pq; //max queue. <count, num> 
        for(auto& iter: count) {
            pq.push({iter.second, iter.first}); 
        };

        vector<int> res;
        for(int i=0; i<k; i++) {
            if(!pq.empty()) {
                res.push_back(pq.top().second);
                pq.pop();
            };
        }
        return res;
    }
};