// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int, int>>> pq; //pair: num, idx.
        unordered_map<int, int> count;
        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});
            count[nums[i]]++;
        };
        vector<int> rets(nums.size(), 0);
        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            rets[t.second] = pq.size()-count[nums[t.second]]+1;
            count[nums[t.second]]--;
        }
        return rets;
    }
};