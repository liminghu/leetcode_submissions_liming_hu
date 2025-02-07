// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> output;
        sort(nums.begin(), nums.end()); //O(nlog(n)), worst(n^2)
		for (int i = 0; i < nums.size(); i++) {
            if(((i > 0) && (nums[i] == nums[i-1])))
                continue;			
			int low = i+1;
			int high = nums.size()-1;
			int sum = 0-nums[i];
			while( low < high ) {
				if( nums[low] + nums[high] == sum) {
				    output.push_back({nums[i], nums[low], nums[high]});
					while(low < high && nums[low] == nums[low+1]) low++;
					while(low < high && nums[high] == nums[high-1]) high--;
					low++;
					high--;
				} else if( nums[low] + nums[high] > sum ) {
					high--;
				} else {
					low++;
				}
			}
		}
			
		return output;
    }
};