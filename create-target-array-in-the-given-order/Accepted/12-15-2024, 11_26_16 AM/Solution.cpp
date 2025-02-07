// https://leetcode.com/problems/create-target-array-in-the-given-order

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> rets;
        for(int i=0; i<nums.size(); i++) {
            rets.insert(rets.begin()+index[i], nums[i]);    //0 <= index[i] <= i
        };
        return rets;
    }
};