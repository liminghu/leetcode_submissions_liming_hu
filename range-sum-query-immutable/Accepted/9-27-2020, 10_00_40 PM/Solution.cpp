// https://leetcode.com/problems/range-sum-query-immutable


class NumArray {
public:
    NumArray(vector<int>& nums) {
		sums = nums;
		for(int i=1; i<sums.size(); i++)
			sums[i] +=sums[i-1];
    }
    
    int sumRange(int i, int j) {
        return i==0? sums[j]: sums[j]-sums[i-1];
    }
private:
	vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */