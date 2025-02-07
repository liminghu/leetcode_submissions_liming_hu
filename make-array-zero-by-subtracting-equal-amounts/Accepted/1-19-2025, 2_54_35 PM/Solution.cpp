// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& nums) {//0 <= nums[i] <= 100
        unordered_set<int> s(nums.begin(), nums.end());
        s.erase(0);
        return s.size();
    }
};