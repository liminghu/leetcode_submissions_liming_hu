// https://leetcode.com/problems/random-pick-index


class Solution {
public:
    Solution(vector<int>& nums) {
       nums_ = nums; 
    }
    
    int pick(int target) {
        int winner = -1;
        int num_target = 0;
        for(int i=0; i<nums_.size(); i++) {
            if(nums_[i] == target) {
                num_target += 1;
                if(rand() % num_target == num_target-1)
                    winner = i;
            }
        }
        return winner;
    }
private:
    vector<int> nums_;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */