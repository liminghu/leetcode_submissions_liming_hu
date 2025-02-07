// https://leetcode.com/problems/3sum-smaller

class Solution {
public:
    int twoSumSmaller(vector<int>& nums, int start_index, int target) { 
        int ans=0;
        int left = start_index;
        int right = nums.size()-1;
        while(left<right) {
            if(nums[left]+nums[right]<target) {
                ans+=right-left; //there are right-left pairs satisfy the condition.
                left++;
            }else {
                right--;
            }
        }
        return ans;
    }

    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        if(n<3)
            return ans;
        sort(nums.begin(), nums.end()); //increasing

        for(int i=0; i<n-2; i++) {
            ans+= twoSumSmaller(nums, i+1, target-nums[i]);
        };

        return ans;
    }
};