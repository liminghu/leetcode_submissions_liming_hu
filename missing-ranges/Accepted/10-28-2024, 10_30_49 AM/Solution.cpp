// https://leetcode.com/problems/missing-ranges

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> rets;
        int n = nums.size();
        if(n==0) {
            rets.push_back({lower, upper});
            return rets;
        };
        if(lower<nums[0]) {
            rets.push_back({lower, nums[0]-1});
        }
        for(int i=0; i<n-1; i++) {
            if(nums[i+1]-nums[i] <=1)
                continue;
            rets.push_back({nums[i]+1, nums[i+1]-1});
        }
        if(upper > nums[n-1]) {
            rets.push_back({nums[n-1]+1, upper});
        }
        return rets;
    }
};