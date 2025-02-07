// https://leetcode.com/problems/random-pick-index

/*
Given an integer array nums with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.
Implement the Solution class:
Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple 
valid i's, then each index should have an equal probability of returning.
*/
class Solution {
private:
    unordered_map<int, vector<int>> mp_;
public:
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            mp_[ nums[i] ].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> idxes = mp_[target];
        int r = random() % idxes.size();
        return idxes[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */