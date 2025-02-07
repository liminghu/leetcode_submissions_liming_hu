// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { //distinct.
        vector<vector<int>> output;
        output.push_back({});
        for(int num: nums) {
            vector<vector<int>> newSubsets;
            for(vector<int> cur: output) {
                vector<int> temp = cur;
                temp.push_back(num);
                newSubsets.push_back(temp);
            };

            for(vector<int> cur:newSubsets) {
                output.push_back(cur);
            }
        }
        return output;

    }

};