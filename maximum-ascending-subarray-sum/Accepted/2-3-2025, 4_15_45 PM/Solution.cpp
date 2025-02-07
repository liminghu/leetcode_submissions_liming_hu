// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {//1 <= nums.length <= 100, 1 <= nums[i] <= 100
        int maxSum = 0;
        int n = nums.size();
        int i=0;
        while(i<n) {
            int sum = nums[i];
            int j=i+1;
            for(; j<n; j++) {
                if(nums[j]>nums[j-1]) 
                    sum += nums[j];
                else 
                    break;
            }
            //cout << "J:" << j << endl;
            //cout << "sum:" << sum << endl;
            maxSum = max(maxSum, sum);
            i = j;
        }
        return maxSum;
        
    }
};