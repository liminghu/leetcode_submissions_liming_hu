// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) { //1 <= nums[i] <= 100
        int ret = 0;
        int n = nums.size();
        vector<int> count(101, 0);
        for(int num: nums)
            count[num]++;
        nums.push_back(0);
        nums.push_back(0);
        for(int i=0; i<n; i++) {
            if(count[ nums[i] ] > 1 ) {
                count[ nums[i]   ]--;
                count[ nums[i+1] ]--;
                count[ nums[i+2] ]--;
                ret++;
            };
        };
        return ret;
    }
};