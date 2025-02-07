// https://leetcode.com/problems/last-stone-weight-ii

/*You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose any two stones and smash them 
together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone. If there are no stones left, return 0.
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*  1 <= stones.length <= 30
            1 <= stones[i] <= 100
        */
        unordered_set<int> set({0});
        for(auto x:stones) {
            auto set_temp = set;
            set.clear();
            for(auto s:set_temp) {
                set.insert(s+x);
                set.insert(s-x);
            };
        }

        int res = INT_MAX;
        for(auto x:set) {
            if(x>=0 && x<res)
                res = x;
        }
        return res;
    }
};