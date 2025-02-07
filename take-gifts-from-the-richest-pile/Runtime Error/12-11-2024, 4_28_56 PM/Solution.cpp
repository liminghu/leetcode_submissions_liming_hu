// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>> pq;
        for(auto& gift: gifts)
            pq.push(gift);
        int i=0;
        while(i<k) {
            int t = pq.top();
            pq.pop();
            int kept = floor(sqrt(t));
            pq.push(kept);
            i++;
        }
        int sum = 0;
        while(!pq.empty()) {
            int t= pq.top();
            pq.pop();
            sum += t;
        }
        return sum;
    }
};