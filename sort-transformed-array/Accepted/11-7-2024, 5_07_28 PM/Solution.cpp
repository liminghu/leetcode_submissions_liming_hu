// https://leetcode.com/problems/sort-transformed-array

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> rets;
        int left = 0;
        int right = nums.size()-1;
        if( a < 0 ) {
            while(left <=right) {
                int leftVal = transform(nums[left], a, b, c);
                int rightVal = transform(nums[right], a, b, c);
                if(leftVal < rightVal) {
                    rets.push_back(leftVal);
                    left++;
                } else {
                    rets.push_back(rightVal);
                    right--;
                }
            }
        } else {
            while(left <=right) {
                int leftVal = transform(nums[left], a, b, c);
                int rightVal = transform(nums[right], a, b, c);
                if(leftVal > rightVal) {
                    rets.push_back(leftVal);
                    left++;
                } else {
                    rets.push_back(rightVal);
                    right--;
                }
            }
            reverse(rets.begin(), rets.end());
        } 
        return rets;

    }
    int transform(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }
};