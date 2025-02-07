// https://leetcode.com/problems/special-array-i

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        //different parity
        bool special = true;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]%2 ==nums[i+1]%2)
                return false;
        }
        return true;
    }
};