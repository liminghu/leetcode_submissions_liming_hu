// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii

class Solution {
public:
    //vector<int> ans;
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        int cur = 0; //just maintain curr variable which tells which element have to be flip
        int cnt = 0;

        for(int i=0; i<nums.size(); i++) {
            if(cur==nums[i]) {
                cnt++;    //Serially flip the element which have to be flipped
                cur = 1- cur;
            }
        }
        return cnt;   
    }
};