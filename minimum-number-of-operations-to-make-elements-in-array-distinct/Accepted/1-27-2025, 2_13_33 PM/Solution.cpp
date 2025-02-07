// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) { //1 <= nums[i] <= 100
        int n = nums.size();
        vector<int> count(101, 0);
        for(int i=n-1; i>=0; i--) {
            count[nums[i]]++;
            if(count[nums[i]]>1)
                return ceil((i+1)*1.0/3);
        }
        return 0;
    }
};