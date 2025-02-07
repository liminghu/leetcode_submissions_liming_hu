// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

/*
A triplet is an array of three integers. You are given a 2D integer array triplets, where triplets[i] = [ai, bi, ci] 
describes the ith triplet. You are also given an integer array target = [x, y, z] that describes the triplet you want to obtain.

To obtain target, you may apply the following operation on triplets any number of times (possibly zero):

Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be updated to 
[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

1 <= triplets.length <= 105
triplets[i].length == target.length == 3
1 <= ai, bi, ci, x, y, z <= 1000
*/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //triplets[i] = [ai, bi, ci]
        //target = [x, y, z]
        //Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
        bool reach_t1 = false;
        bool reach_t2 = false;
        bool reach_t3 = false;
        int n = triplets.size();
        for(auto triple: triplets) {
            if(triple[0] == target[0] && triple[1] <= target[1] && triple[2] <= target[2] )
                reach_t1 = true;   //this triple can be used to merget to target[0]
            if(triple[1] == target[1] && triple[0] <= target[0] && triple[2] <= target[2] )
                reach_t2 = true;   //this triple can be used to merget to target[1]
            if(triple[2] == target[2] && triple[0] <= target[0] && triple[1] <= target[1] )
                reach_t3 = true;   //this triple can be used to merget to target[2]
        }
        return reach_t1 && reach_t2 && reach_t3;
    }
};