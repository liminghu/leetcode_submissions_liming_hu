// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> rets(nums.size(), 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<nums.size(); i++)
            pq.push({nums[i], i});
        int i=0;
        while(i<k) {
            pair<int, int> t = pq.top();
            pq.pop();
            pq.push({t.first*multiplier, t.second});
            i++;
        }
        while(!pq.empty()){
            pair<int, int> t = pq.top();
            pq.pop();
            rets[t.second] = t.first;
        };
        return rets;
    }
};