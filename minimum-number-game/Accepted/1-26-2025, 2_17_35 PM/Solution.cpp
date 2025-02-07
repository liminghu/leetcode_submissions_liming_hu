// https://leetcode.com/problems/minimum-number-game

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++) {
            int alice = nums[2*i];
            int bob = nums[2*i+1];
            arr[2*i] = bob;
            arr[2*i+1] = alice;
        }
        return arr;
    }
};