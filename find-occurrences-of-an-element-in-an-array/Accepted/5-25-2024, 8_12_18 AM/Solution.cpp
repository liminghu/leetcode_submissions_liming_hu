// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans(queries.size(), -1);

        unordered_map<int, vector<int>> nums_count;
        for(int i=0; i<nums.size(); i++) {
            nums_count[nums[i]].push_back(i);
        }

        vector<int> x_count;
        if(nums_count.find(x) == nums_count.end())
            return ans;
        else
            x_count = nums_count[x];

        for(int i=0; i<queries.size(); i++) {
            if(x_count.size() < queries[i])
                ans[i] = -1;
            else {
                ans[i] = x_count[queries[i]-1];
            }

        }
        return ans;

        
    }
};