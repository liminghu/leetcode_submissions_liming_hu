// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
		int half = length%2 == 0? length/2 : length/2+1
        int ans =0;
		unordered_map<int,int> m;
		for(int i=0; i<nums.size(); i++) {
			m[nums[i]]++;
			if(m[nums[i]] >= half)
				ans= nums[i];
		}
		
        return ans;
    }
};