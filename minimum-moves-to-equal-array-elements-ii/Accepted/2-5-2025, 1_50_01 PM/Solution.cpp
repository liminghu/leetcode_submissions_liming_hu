// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //In one move, you can increment or decrement an element of the array by 1.
        int mid = n/2;
        int steps = 0;
        for(int i=0; i<n; i++)
            steps += abs(nums[i] - nums[mid]);
        return steps;
    }
};