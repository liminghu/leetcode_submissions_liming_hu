// https://leetcode.com/problems/3sum-closest

class Solution {
public:
/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
*/
    int threeSumClosest(vector<int>& nums, int target) { //3 <= nums.length <= 500
                                                         //-1000 <= nums[i] <= 1000
                                                         //-104 <= target <= 104     
        int sz = nums.size();

        if(sz == 3)
            return nums[0]+nums[1]+nums[2];


		int closest = INT_MAX;
        sort(nums.begin(), nums.end()); //O(nlog(n)), worst(n^2)
		for (int i = 0; i < nums.size(); i++) {		
			int low = i+1;
			int high = nums.size()-1;
			while( low < high ) {
                int sum3 = nums[low] + nums[high] + nums[i];
                if( abs(sum3-(float)target) < abs(closest-(float)target) )
                    closest = sum3;
				if( sum3 < target) {
					low++;
				} else if( sum3 > target ) {
					high--;
				} else {
					return closest;
				}
			}
		}
			
		return closest;
        
    }
};