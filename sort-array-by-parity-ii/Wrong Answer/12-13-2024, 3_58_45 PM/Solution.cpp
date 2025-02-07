// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(i%2 == nums[i]%2)
                continue;
            int j = i+1;
            while(j<n && (j%2 == nums[j]%2))
                j++;
            if(j<n)
                swap(nums[i], nums[j]);                
        }
        return nums;
    }
};