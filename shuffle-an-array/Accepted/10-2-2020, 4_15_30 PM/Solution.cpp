// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
		output_ = nums_;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
       output_ = nums_; 
	   return output_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		for(int i=0; i<output_.size(); i++) {
			int pos = rand() % (output_.size()-i);
			swap(output_[i+pos], output_[i]);
		}
		return output_;
        
    }
private:
	vector<int> nums_;
	vector<int> output_;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */