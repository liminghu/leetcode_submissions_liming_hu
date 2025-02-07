// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        int ans =0;
		unordered_map<int,int> m;
		for(int i=0; i<nums.size(); i++) {
			m[nums[i]]++;
			if(m[nums[i]] >= length/2)
				ans= nums[i];
		}
		
        return ans;
    }
};