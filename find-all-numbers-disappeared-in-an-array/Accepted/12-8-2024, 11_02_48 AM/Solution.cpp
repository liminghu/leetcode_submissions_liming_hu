// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> rets;
        int count = 1;
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int> > pq; //min
        for(auto& num:nums) 
                pq.push(num);
 
        while(count<=n) {
            if(!pq.empty() && pq.top() == count) {
                int t = pq.top();
                pq.pop();
                while(!pq.empty() && pq.top() == t)
                    pq.pop();
            }else 
                rets.push_back(count);
            count++;
        };
        return rets;

    }
};