// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size(), 0);
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i>0)
                prefixSum[i] = prefixSum[i-1]+nums[i];
            else
                prefixSum[i] = nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left >0)
            return prefixSum[right]-prefixSum[left-1];
        else
            return prefixSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */