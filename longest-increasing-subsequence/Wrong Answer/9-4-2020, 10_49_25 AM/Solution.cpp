// https://leetcode.com/problems/longest-increasing-subsequence


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { //DP
        
        if(nums.size() == 0) return 0;
		vector<int> len_LIS(nums.size(),1);
		for(int i=1; i<nums.size(); i++) {
			for(int j=0; j<i; j++) {
				if ( (nums[j] <=nums[i]) && len_LIS[i] < len_LIS[j] +1) {
					len_LIS[i] = len_LIS[j] +1;
				};
			};
		};
		
		int max_len =1;
		for(int i=1; i<len_LIS.size(); i++) {
			 if (len_LIS[i] > max_len )
				 max_len = len_LIS[i];
		};
		
		return max_len;
				
        
    }
};