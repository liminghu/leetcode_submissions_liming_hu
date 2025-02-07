// https://leetcode.com/problems/last-stone-weight

/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash 
them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size() >=2) {
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            if(t1!=t2)
                pq.push(abs(t2-t1));
        }
        int res = 0;
        if(!pq.empty() && pq.size()==1)
            res = pq.top();
        return res;
    }
};