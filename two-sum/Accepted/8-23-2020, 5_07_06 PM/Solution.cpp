// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      	unordered_map<int, int> mNum;
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i) {
			int left = target - nums[i];
			if (mNum.find(left) != mNum.end() ) { //the left is found.
				result.push_back(i);
				result.push_back(mNum[left]);
				return result;
			}
			mNum[nums[i]] = i;
			
		}
		return {};  
    }
};