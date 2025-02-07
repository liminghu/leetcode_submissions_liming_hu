// https://leetcode.com/problems/4sum

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { //1 <= nums.length <= 200
                                                                //-109 <= nums[i] <= 109
                                                                //-109 <= target <= 109
        vector<vector<int>> ans = {};
        int sz = nums.size();

        if(sz < 4)
            return ans;

        sort(nums.begin(), nums.end());
        for(int i=0; i<sz-3; i++) {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<sz-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int left = j+1;
                int right = sz-1;
                int sum2 = nums[i] + nums[j];
                while(left < right) {
                    int sum = sum2 + nums[left] + nums[right];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left+1<right && nums[left+1]== nums[left] )
                            left++;
                        while(right-1> left && nums[right] == nums[right-1])
                            right--;
                        left++;
                        right--;
                    } else if(sum>target) {
                        right--;
                    } else if(sum<target) {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};